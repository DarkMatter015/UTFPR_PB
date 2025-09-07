use BDLojaInstrumentosMusicais
use master


-- View 1: Fazer uma view que exiba o estoque atual de cada produto, deve exibir nome, tipo, marca e quantidade atual em estoque. Cada produto deve aparecer uma única vez na listagem. 
-- Exibir inclusive os produtos com estoque zero.

create or alter view V_ESTOQUE_PRODUTOS
as
	select p.nome nome_produto, tp.nome tipo_produto, m.nome marca, 
		COALESCE ((
		select top 1 em.quantidade_atual
		from Estoque_Movimentacao em
		where em.id_produto = p.id_produto
		order by em.data_hora desc
		), 0) quantidade_atual

	from Produto p

	inner join TipoProduto tp
	on tp.id_tipo_produto = p.id_tipo_produto

	inner join Marca m
	on m.id_marca = p.id_marca

select nome_produto, tipo_produto, marca, quantidade_atual from V_ESTOQUE_PRODUTOS


-- View 2: Fazer uma view que exiba uma listagem de clientes e suas compras, exibindo todos os dados do cliente, produtos que comprou e quando comprou, e quantidades compradas. 
-- Bem como se utilizou a garantia

create or alter view V_COMPRAS_CLIENTES
as
	select c.nome nome_cliente, c.cpf, c.email, c.telefone, c.data_nascimento, en.logradouro, en.numero, en.bairro, ci.nome cidade, es.sigla UF, pa.sigla pais, COALESCE(pro.nome, 'Sem produtos') produto_comprado, em.data_hora data_hora_compra, COALESCE(em.quantidade_movimentada, 0) qtd_comprada,
	CASE 
        WHEN EXISTS (SELECT g.id_garantia FROM Garantia g WHERE g.id_venda = ve.id_venda) 
        THEN 'Sim' 
        ELSE 'Não' 
    END AS garantia_utilizada

	from Cliente c

	inner join Endereco en on en.id_endereco = c.id_endereco

	inner join Cidade ci on ci.id_cidade = en.id_cidade

	inner join Estado es on es.id_estado = ci.id_estado

	inner join Pais pa on pa.id_pais = es.id_pais

	left join Venda ve on c.id_cliente = ve.id_cliente

	left join Estoque_Movimentacao em on ve.id_venda = em.id_venda AND em.tipo_movimentacao = 'S'

	left join Produto pro on em.id_produto = pro.id_produto

select nome_cliente, cpf, email, telefone, data_nascimento, logradouro, numero, bairro, cidade, UF, pais, produto_comprado, data_hora_compra, qtd_comprada, garantia_utilizada
from V_COMPRAS_CLIENTES


-- Procedures de CRUD: fazer as procedures de insert, delete, update e select para a tabela Produto.
-- SP de INSERT
CREATE OR ALTER PROCEDURE SP_INS_PRODUTO
(
    @ID_PRODUTO INT OUTPUT,
    @NOME VARCHAR(100),
    @DESCRICAO VARCHAR(255),
    @PRECO_VENDA DECIMAL(10,2),
    @PRECO_CUSTO DECIMAL(10,2),
    @GARANTIA_MESES INT,
    @ID_TIPO_PRODUTO INT,
    @ID_MARCA INT,
    @ATIVO BIT
)
AS
BEGIN
    INSERT INTO Produto (nome, descricao, preco_venda, preco_custo, garantia_meses, id_tipo_produto, id_marca, ativo)
    VALUES (@NOME, @DESCRICAO, @PRECO_VENDA, @PRECO_CUSTO, @GARANTIA_MESES, @ID_TIPO_PRODUTO, @ID_MARCA, @ATIVO);

    SET @ID_PRODUTO = @@IDENTITY;
    PRINT @ID_PRODUTO;
END;

-- INSERT
DECLARE @ID_PRODUTO INT;
EXEC SP_INS_PRODUTO @ID_PRODUTO OUTPUT, 'Violão Yamaha C40', 'Violão clássico com cordas de nylon', 1200.00, 800.00, 12, 1, 2, 1;


-- SP de DELETE
CREATE OR ALTER PROCEDURE SP_DEL_PRODUTO
(
    @STATUS INT OUTPUT,
    @ID_PRODUTO INT
)
AS
BEGIN
    DELETE FROM Produto 
    WHERE id_produto = @ID_PRODUTO;

    IF (@@ERROR <> 0)
        SET @STATUS = -1;
    ELSE
        SET @STATUS = 0;

    PRINT @STATUS;
END;

-- DELETE ID = 5
DECLARE @STATUS INT;
EXEC SP_DEL_PRODUTO @STATUS OUTPUT, 5;

-- SP de UPDATE
CREATE OR ALTER PROCEDURE SP_UPD_PRODUTO
(
    @ID_PRODUTO INT,
    @NOME VARCHAR(100),
    @DESCRICAO VARCHAR(255),
    @PRECO_VENDA DECIMAL(10,2),
    @PRECO_CUSTO DECIMAL(10,2),
    @GARANTIA_MESES INT,
    @ID_TIPO_PRODUTO INT,
    @ID_MARCA INT,
    @ATIVO BIT,
    @STATUS INT OUTPUT
)
AS
BEGIN
    UPDATE Produto
    SET 
        nome = @NOME,
        descricao = @DESCRICAO,
        preco_venda = @PRECO_VENDA,
        preco_custo = @PRECO_CUSTO,
        garantia_meses = @GARANTIA_MESES,
        id_tipo_produto = @ID_TIPO_PRODUTO,
        id_marca = @ID_MARCA,
        ativo = @ATIVO
    WHERE id_produto = @ID_PRODUTO;

    IF (@@ERROR <> 0)
        SET @STATUS = -1;
    ELSE
        SET @STATUS = 0;

    PRINT @STATUS;
END;

select * from Produto
-- UPDATE 
DECLARE @STATUS INT;
EXEC SP_UPD_PRODUTO 1, 'Guitarra Elétrica Fender Stratocaster Atualizada', 'Guitarra com captadores single-coil', 7800.00, 5700.00, 12, 1, 1, 1, @STATUS OUTPUT;

-- SP de SELECT
CREATE OR ALTER PROCEDURE SP_SEL_PRODUTO
(
    @ID_PRODUTO INT = NULL,
    @NOME VARCHAR(100) = NULL,
    @DESCRICAO VARCHAR(255) = NULL,
    @PRECO_VENDA DECIMAL(10,2) = NULL,
    @PRECO_CUSTO DECIMAL(10,2) = NULL,
    @GARANTIA_MESES INT = NULL,
    @ID_TIPO_PRODUTO INT = NULL,
    @ID_MARCA INT = NULL,
    @ATIVO BIT = NULL
)
AS
BEGIN
    SELECT 
        id_produto,
        nome nome_produto,
        descricao,
        preco_venda,
        preco_custo,
        garantia_meses,
        id_tipo_produto,
        id_marca,
        ativo
    FROM Produto
    WHERE 
        ((@ID_PRODUTO IS NULL) OR (id_produto = @ID_PRODUTO))
        AND ((@NOME IS NULL) OR (nome = @NOME))
        AND ((@DESCRICAO IS NULL) OR (descricao like '%' + @DESCRICAO + '%'))
        AND ((@PRECO_VENDA IS NULL) OR (preco_venda = @PRECO_VENDA))
        AND ((@PRECO_CUSTO IS NULL) OR (preco_custo = @PRECO_CUSTO))
        AND ((@GARANTIA_MESES IS NULL) OR (garantia_meses = @GARANTIA_MESES))
        AND ((@ID_TIPO_PRODUTO IS NULL) OR (id_tipo_produto = @ID_TIPO_PRODUTO))
        AND ((@ID_MARCA IS NULL) OR (id_marca = @ID_MARCA))
        AND ((@ATIVO IS NULL) OR (ativo = @ATIVO))
END;

EXEC SP_SEL_PRODUTO NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL; -- Todos os produtos
EXEC SP_SEL_PRODUTO 1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL; -- id_produto = 1


-- Procedure 1: Criar uma procedure que receba como parâmetro de entrada o nome de um FORNECEDOR e imprima a lista de todos os PRODUTOS que foram adquiridos com este fornencedor, 
-- imprimir, nome, marca e tipo e quantidade atual deste produto em estoque.

CREATE OR ALTER PROCEDURE SP_SEL_PRODUTOS_DE_FORNECEDOR
(
    @NOME VARCHAR(100)
)
AS
BEGIN
	SELECT 
        p.nome nome_produto,
        m.nome marca,
        tp.nome tipo_produto,
		COALESCE ((
		select top 1 em.quantidade_atual
		from Estoque_Movimentacao em
		where em.id_produto = p.id_produto
		order by em.data_hora desc
		), 0) quantidade_atual
    FROM Produto p
	INNER JOIN Marca m on p.id_marca = m.id_marca
	INNER JOIN TipoProduto tp on p.id_tipo_produto = tp.id_tipo_produto
	LEFT JOIN Estoque_Movimentacao em on p.id_produto = em.id_produto
	INNER JOIN Compra c on em.id_compra = c.id_compra
	INNER JOIN Fornecedor f on c.id_fornecedor = f.id_fornecedor
    WHERE 
		f.nome_fantasia = @NOME

END;

EXEC SP_SEL_PRODUTOS_DE_FORNECEDOR 'MusicSupply'
select * from Fornecedor
select * from Compra

INSERT INTO Compra (data_hora, valor_total, id_status_compra, id_funcionario, id_fornecedor, id_forma_pagamento) VALUES
    (CONVERT(DATETIME, '2025-07-06 09:00:00', 120), 5500.00, 2, 1, 1, 1)

INSERT INTO Estoque_Movimentacao (tipo_movimentacao, quantidade_anterior, quantidade_atual, quantidade_movimentada, data_hora, valor_unitario, id_compra, id_venda, id_produto)
VALUES ('E', 0, 0, 5, '2025-07-06 20:00:00', 1100.00, 5, NULL, 1);


-- Procedure 2: Criar uma procedure que receba como parâmetro o nome de um funcionário e imprima todos os produtos que ele vendeu no mês passado.

CREATE OR ALTER PROCEDURE SP_SEL_VENDAS_FUNCIONARIO
(
	@NOME VARCHAR(100)
)
AS
BEGIN
	-- DATA ANTERIOR
	DECLARE @DataAtual DATE = GETDATE()
	DECLARE @DataMesAnterior DATE = DATEADD(MONTH, -1, @DataAtual)

	DECLARE @DataInicio DATE = DATEFROMPARTS(
			YEAR(@DataMesAnterior),
			MONTH(@DataMesAnterior),
			1
		)

	DECLARE @DataFim DATE = EOMONTH(@DataMesAnterior)
	
	SELECT 
		p.nome produto_vendido,
		m.nome AS marca,
        tp.nome AS tipo_produto,
		em.quantidade_movimentada qtd_vendida,
		v.valor_total,
		v.data_hora data_hora_venda

	FROM Produto p
	INNER JOIN Marca m ON p.id_marca = m.id_marca
    INNER JOIN TipoProduto tp ON p.id_tipo_produto = tp.id_tipo_produto
	INNER JOIN Estoque_Movimentacao em on p.id_produto = em.id_produto AND em.tipo_movimentacao = 'S'
	INNER JOIN Venda v on em.id_venda = v.id_venda
	INNER JOIN Funcionario f on v.id_funcionario = f.id_funcionario

	WHERE 
		f.nome = @NOME 
		AND v.data_hora >= @DataInicio 
		AND v.data_hora <= @DataFim
END;

EXEC SP_SEL_VENDAS_FUNCIONARIO 'Fernanda Lima'
select nome from Funcionario
select * from Venda


-- TRIGGERS
-- Trigger de LOG 1: Trigger log na tabela fornecedor, deve efetuar o log gravando registro novo, velho, usuário e data_hora da operação, e operação realizada.
SELECT * FROM Fornecedor
select * from LOG_FORNECEDOR
DROP TABLE IF EXISTS LOG_FORNECEDOR

CREATE TABLE LOG_FORNECEDOR
(
    ID_FORNECEDOR INT CONSTRAINT NN_IdFornecedor_LOGFORNECEDOR NOT NULL,
    NOME_FANTASIA VARCHAR(100) CONSTRAINT NN_NomeFantasia_LOGFORNECEDOR NOT NULL,
    RAZAO_SOCIAL VARCHAR(150) CONSTRAINT NN_RazaoSocial_LOGFORNECEDOR NOT NULL,
    CNPJ CHAR(14) CONSTRAINT NN_Cnpj_LOGFORNECEDOR NOT NULL,
    TELEFONE VARCHAR(20),
    EMAIL VARCHAR(100),
    NOME_REPRESENTANTE VARCHAR(255),
    ID_ENDERECO INT CONSTRAINT NN_Endereco_LOGFORNECEDOR NOT NULL,
    OPERACAO CHAR(1) CONSTRAINT NN_Operacao_LOGFORNECEDOR NOT NULL,
    HORARIOLOG DATETIME CONSTRAINT NN_HorarioLog_LOGFORNECEDOR NOT NULL,
    USUARIO CHAR(30) CONSTRAINT NN_Usuario_LOGFORNECEDOR NOT NULL
)


-- Criação da trigger
CREATE OR ALTER TRIGGER TG_LOG_FORNECEDOR
ON Fornecedor
FOR INSERT, UPDATE, DELETE
AS
BEGIN
    DECLARE @ID_FORNECEDOR INT,
            @NOME_FANTASIA VARCHAR(100),
            @RAZAO_SOCIAL VARCHAR(150),
            @CNPJ CHAR(14),
            @EMAIL VARCHAR(100),
            @TELEFONE VARCHAR(20),
            @NOME_REPRESENTANTE VARCHAR(255),
            @ID_ENDERECO INT,
            @OPERACAO CHAR(1),
            @HORARIO_LOG DATETIME,
            @USUARIO CHAR(30)

    -- UPDATE
    IF EXISTS (SELECT * FROM DELETED) AND EXISTS (SELECT * FROM INSERTED)
    BEGIN
        SELECT 
            @ID_FORNECEDOR = id_fornecedor,
            @NOME_FANTASIA = nome_fantasia,
            @RAZAO_SOCIAL = razao_social,
            @CNPJ = cnpj,
            @EMAIL = email,
            @TELEFONE = telefone,
            @NOME_REPRESENTANTE = nome_representante,
            @ID_ENDERECO = id_endereco
        FROM DELETED

        INSERT INTO LOG_FORNECEDOR
        VALUES (@ID_FORNECEDOR, @NOME_FANTASIA, @RAZAO_SOCIAL, @CNPJ, @EMAIL, @TELEFONE, @NOME_REPRESENTANTE, @ID_ENDERECO, 'U', GETDATE(), CURRENT_USER)

		SELECT 
            @ID_FORNECEDOR = id_fornecedor,
            @NOME_FANTASIA = nome_fantasia,
            @RAZAO_SOCIAL = razao_social,
            @CNPJ = cnpj,
            @EMAIL = email,
            @TELEFONE = telefone,
            @NOME_REPRESENTANTE = nome_representante,
            @ID_ENDERECO = id_endereco
        FROM INSERTED

        INSERT INTO LOG_FORNECEDOR
        VALUES (@ID_FORNECEDOR, @NOME_FANTASIA, @RAZAO_SOCIAL, @CNPJ, @EMAIL, @TELEFONE, @NOME_REPRESENTANTE, @ID_ENDERECO, 'U', GETDATE(), CURRENT_USER)

        PRINT 'Dados de um fornecedor foram atualizados.'
    END

    -- INSERT
    IF NOT EXISTS (SELECT * FROM DELETED) AND EXISTS (SELECT * FROM INSERTED)
    BEGIN
        SELECT 
            @ID_FORNECEDOR = id_fornecedor,
            @NOME_FANTASIA = nome_fantasia,
            @RAZAO_SOCIAL = razao_social,
            @CNPJ = cnpj,
            @EMAIL = email,
            @TELEFONE = telefone,
            @NOME_REPRESENTANTE = nome_representante,
            @ID_ENDERECO = id_endereco
        FROM INSERTED

        INSERT INTO LOG_FORNECEDOR
        VALUES (@ID_FORNECEDOR, @NOME_FANTASIA, @RAZAO_SOCIAL, @CNPJ, @EMAIL, @TELEFONE, @NOME_REPRESENTANTE, @ID_ENDERECO, 'I', GETDATE(), CURRENT_USER)

        PRINT 'Dados de um fornecedor foram inseridos.'
    END

    -- DELETE
    IF EXISTS (SELECT * FROM DELETED) AND NOT EXISTS (SELECT * FROM INSERTED)
    BEGIN
        SELECT 
            @ID_FORNECEDOR = id_fornecedor,
            @NOME_FANTASIA = nome_fantasia,
            @RAZAO_SOCIAL = razao_social,
            @CNPJ = cnpj,
            @EMAIL = email,
            @TELEFONE = telefone,
            @NOME_REPRESENTANTE = nome_representante,
            @ID_ENDERECO = id_endereco
        FROM DELETED

        INSERT INTO LOG_FORNECEDOR
        VALUES (@ID_FORNECEDOR, @NOME_FANTASIA, @RAZAO_SOCIAL, @CNPJ, @EMAIL, @TELEFONE, @NOME_REPRESENTANTE, @ID_ENDERECO, 'D', GETDATE(), CURRENT_USER)

        PRINT 'Dados de um fornecedor foram deletados.'
    END
END


-- INSERT
INSERT INTO Fornecedor (nome_fantasia, razao_social, cnpj, email, telefone, nome_representante, id_endereco)
VALUES ('Teste Fornecedor', 'Teste Fornecedor LTDA', '12345678901234', 'teste@email.com', '11987654321', 'João Representante', 1);
SELECT * FROM Fornecedor;
SELECT * FROM LOG_FORNECEDOR;

-- UPDATE
UPDATE Fornecedor 
SET nome_fantasia = 'Teste Fornecedor Atualizado', nome_representante = 'Maria Representante'
WHERE id_fornecedor = 5;
SELECT * FROM Fornecedor;
SELECT * FROM LOG_FORNECEDOR;

-- DELETE
DELETE FROM Fornecedor 
WHERE id_fornecedor = 5;
SELECT * FROM Fornecedor;
SELECT * FROM LOG_FORNECEDOR;

-- Trigger de LOG 2: Trigger log na tabela cliente, deve efetuar o log gravando registro novo, velho, usuário e data_hora da operação, e operação realizada.
DROP TABLE IF EXISTS LOG_CLIENTE

CREATE TABLE LOG_CLIENTE
(
    ID_CLIENTE INT CONSTRAINT NN_IdCliente_LOGCLIENTE NOT NULL,
    NOME VARCHAR(100) CONSTRAINT NN_Nome_LOGCLIENTE NOT NULL,
    CPF CHAR(11) CONSTRAINT NN_Cpf_LOGCLIENTE NOT NULL,
    EMAIL VARCHAR(100) CONSTRAINT NN_Email_LOGCLIENTE NOT NULL,
    TELEFONE CHAR(11) CONSTRAINT NN_Telefone_LOGCLIENTE NOT NULL,
    DATA_NASCIMENTO DATE CONSTRAINT NN_DataNascimento_LOGCLIENTE NOT NULL,
    DATA_CADASTRO DATETIME CONSTRAINT NN_DataCadastro_LOGCLIENTE NOT NULL,
    ID_ENDERECO INT CONSTRAINT NN_Endereco_LOGCLIENTE NOT NULL,
    OPERACAO CHAR(1) CONSTRAINT NN_Operacao_LOGCLIENTE NOT NULL,
    HORARIOLOG DATETIME CONSTRAINT NN_HorarioLog_LOGCLIENTE NOT NULL,
    USUARIO CHAR(30) CONSTRAINT NN_Usuario_LOGCLIENTE NOT NULL
);

-- Criação da trigger
CREATE OR ALTER TRIGGER TG_LOG_CLIENTE
ON Cliente
FOR INSERT, UPDATE, DELETE
AS
BEGIN
    DECLARE @ID_CLIENTE INT,
            @NOME VARCHAR(100),
            @CPF CHAR(11),
            @EMAIL VARCHAR(100),
            @TELEFONE CHAR(11),
            @DATA_NASCIMENTO DATE,
            @DATA_CADASTRO DATETIME,
            @ID_ENDERECO INT,
            @OPERACAO CHAR(1),
            @HORARIO_LOG DATETIME,
            @USUARIO CHAR(30);

    -- UPDATE
    IF EXISTS (SELECT * FROM DELETED) AND EXISTS (SELECT * FROM INSERTED)
    BEGIN
        
        SELECT 
            @ID_CLIENTE = id_cliente,
            @NOME = nome,
            @CPF = cpf,
            @EMAIL = email,
            @TELEFONE = telefone,
            @DATA_NASCIMENTO = data_nascimento,
            @DATA_CADASTRO = data_cadastro,
            @ID_ENDERECO = id_endereco
        FROM DELETED;

        INSERT INTO LOG_CLIENTE
        VALUES (@ID_CLIENTE, @NOME, @CPF, @EMAIL, @TELEFONE, @DATA_NASCIMENTO, @DATA_CADASTRO, @ID_ENDERECO, 'U', GETDATE(), CURRENT_USER);

        
        SELECT 
            @ID_CLIENTE = id_cliente,
            @NOME = nome,
            @CPF = cpf,
            @EMAIL = email,
            @TELEFONE = telefone,
            @DATA_NASCIMENTO = data_nascimento,
            @DATA_CADASTRO = data_cadastro,
            @ID_ENDERECO = id_endereco
        FROM INSERTED;

        INSERT INTO LOG_CLIENTE
        VALUES (@ID_CLIENTE, @NOME, @CPF, @EMAIL, @TELEFONE, @DATA_NASCIMENTO, @DATA_CADASTRO, @ID_ENDERECO, 'U', GETDATE(), CURRENT_USER);

        PRINT 'Dados de um cliente foram alterados.';
    END

    -- INSERT
    IF NOT EXISTS (SELECT * FROM DELETED) AND EXISTS (SELECT * FROM INSERTED)
    BEGIN
        SELECT 
            @ID_CLIENTE = id_cliente,
            @NOME = nome,
            @CPF = cpf,
            @EMAIL = email,
            @TELEFONE = telefone,
            @DATA_NASCIMENTO = data_nascimento,
            @DATA_CADASTRO = data_cadastro,
            @ID_ENDERECO = id_endereco
        FROM INSERTED;

        INSERT INTO LOG_CLIENTE
        VALUES (@ID_CLIENTE, @NOME, @CPF, @EMAIL, @TELEFONE, @DATA_NASCIMENTO, @DATA_CADASTRO, @ID_ENDERECO, 'I', GETDATE(), CURRENT_USER);

        PRINT 'Dados de um cliente foram inseridos.';
    END

    -- DELETE
    IF EXISTS (SELECT * FROM DELETED) AND NOT EXISTS (SELECT * FROM INSERTED)
    BEGIN
        SELECT 
            @ID_CLIENTE = id_cliente,
            @NOME = nome,
            @CPF = cpf,
            @EMAIL = email,
            @TELEFONE = telefone,
            @DATA_NASCIMENTO = data_nascimento,
            @DATA_CADASTRO = data_cadastro,
            @ID_ENDERECO = id_endereco
        FROM DELETED;

        INSERT INTO LOG_CLIENTE
        VALUES (@ID_CLIENTE, @NOME, @CPF, @EMAIL, @TELEFONE, @DATA_NASCIMENTO, @DATA_CADASTRO, @ID_ENDERECO, 'D', GETDATE(), CURRENT_USER);

        PRINT 'Dados de um cliente foram deletados.';
    END
END

-- INSERT
INSERT INTO Cliente (nome, cpf, email, telefone, data_nascimento, data_cadastro, id_endereco)
VALUES ('Teste Cliente', '29837173', 'teste.cliente@email.com', '11987654321', '1990-01-01', CONVERT(DATETIME, '2025-06-30 12:49:00', 120), 1);
SELECT * FROM Cliente;
SELECT * FROM LOG_CLIENTE;

-- UPDATE
UPDATE Cliente 
SET nome = 'Teste Cliente Atualizado', email = 'teste.atualizado@email.com'
WHERE id_cliente = 5;
SELECT * FROM Cliente;
SELECT * FROM LOG_CLIENTE;

-- DELETE
DELETE FROM Cliente 
WHERE id_cliente = 5;
SELECT * FROM Cliente;
SELECT * FROM LOG_CLIENTE;



/*
Trigger de processamento 1: Trigger na tabela estoque_movimentacao, que será disparada no insert, update ou delete controle corretamente a saída 
e entrada de produtos no estoque, fazendo a baixa ou a entrada no estoque e atualizando a nova quantidade disponível. 
E caso a quantidade a ser vendida não tenha disponível no estoque deve informar o usuário.
*/

CREATE OR ALTER TRIGGER TG_ESTOQUE_MOVIMENTACAO_INSERT
ON Estoque_Movimentacao
AFTER INSERT
AS
BEGIN
        IF EXISTS (
            SELECT i.id_movimentacao_estoque
            FROM INSERTED i
            WHERE i.tipo_movimentacao = 'S'
            AND i.quantidade_anterior < i.quantidade_movimentada
        )
        BEGIN
            PRINT 'Estoque insuficiente para movimentacao';
            ROLLBACK;
            RETURN;
        END

        
		UPDATE em
		SET quantidade_atual = CASE
			WHEN i.tipo_movimentacao = 'E' 
			THEN i.quantidade_anterior + i.quantidade_movimentada
			ELSE i.quantidade_anterior - i.quantidade_movimentada
		END
		FROM Estoque_Movimentacao em
		INNER JOIN INSERTED i ON em.id_movimentacao_estoque = i.id_movimentacao_estoque;

        PRINT 'Inserido com sucesso.';
END;


-- ENTRADA
INSERT INTO Estoque_Movimentacao (tipo_movimentacao, quantidade_anterior, quantidade_atual, quantidade_movimentada, data_hora, valor_unitario, id_compra, id_venda, id_produto)
VALUES ('E', 0, 0, 5, '2025-07-06 19:15:00', 5500.00, NULL, NULL, 1); -- + 5
SELECT * FROM Estoque_Movimentacao WHERE id_produto = 1;

-- SAÍDA COM ESTOQUE SUFICIENTE
INSERT INTO Estoque_Movimentacao (tipo_movimentacao, quantidade_anterior, quantidade_atual, quantidade_movimentada, data_hora, valor_unitario, id_compra, id_venda, id_produto)
VALUES ('S', 5, 0, 3, '2025-07-06 19:16:00', 5500.00, NULL, NULL, 1); -- - 3
SELECT * FROM Estoque_Movimentacao WHERE id_produto = 1;

-- SAÍDA COM ESTOQUE INSUFICIENTE
INSERT INTO Estoque_Movimentacao (tipo_movimentacao, quantidade_anterior, quantidade_atual, quantidade_movimentada, data_hora, valor_unitario, id_compra, id_venda, id_produto)
VALUES ('S', 2, 0, 5, '2025-07-06 19:17:00', 5500.00, NULL, NULL, 1); -- tenta vender 5
SELECT * FROM Estoque_Movimentacao WHERE id_produto = 1;



/*
Trigger de processamento 2: Trigger na tabela garantia que será disparada no insert ou no update, não deve permitir que um cliente, acione a garantia de um mesmo produto mais de uma vez.
Caso isso aconteça, não deve permitir o insert ou o update e informar o usuário por mensagem.
*/

CREATE OR ALTER TRIGGER TG_GARANTIA_INSERT
ON Garantia
AFTER INSERT
AS
BEGIN

	IF EXISTS (
		SELECT g.id_garantia
		FROM Garantia g
		INNER JOIN INSERTED i ON i.id_garantia != g.id_garantia
		WHERE g.id_venda = i.id_venda AND g.id_produto = i.id_produto
	)
	BEGIN
		PRINT 'Garantia ja foi utilizada para esse produto'
		ROLLBACK
		RETURN
	END
	PRINT 'Garantia incluida'
END;

-- GANTIA DUPLICADA
INSERT INTO Garantia (id_venda, id_produto, data_solicitacao, id_status_garantia) 
VALUES (1, 1, '2025-07-06', 1)
select * from Garantia