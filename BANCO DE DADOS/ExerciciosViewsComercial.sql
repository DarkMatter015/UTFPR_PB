-- Criação do banco de dados
CREATE DATABASE SistemaRepresentacaoComercial;
GO

-- Usar o banco de dados criado
USE SistemaRepresentacaoComercial;
GO

-- Tabela CLIENTE
CREATE TABLE CLIENTE (
    CLI_ID INT IDENTITY(1,1) PRIMARY KEY,
    CLI_NM_ENDERECO VARCHAR(200),
    CLI_NM_BAIRRO VARCHAR(100),
    CLI_NM_CIDADE VARCHAR(100),
    CLI_NR_UF DECIMAL(2, 0),
    CLI_NR_CEP DECIMAL(8, 0),
    CLI_NR_TEL VARCHAR(20),
    CLI_NR_FAX VARCHAR(20),
    CLI_NM_CONTATO VARCHAR(50),
    CLI_NM_EMAIL VARCHAR(200),
    CLI_NR_CNPJ VARCHAR(20),
    CLI_NR_INSCREST VARCHAR(20),
    CLI_DS_OBS VARCHAR(4999)
);

-- Tabela REPRESENTADA
CREATE TABLE REPRESENTADA (
    REP_ID INT IDENTITY(1,1) PRIMARY KEY,
    REP_NM_ENDERECO VARCHAR(200),
    REP_NM_BAIRRO VARCHAR(100),
    REP_NM_CIDADE VARCHAR(100),
    REP_NR_UF DECIMAL(2, 0),
    REP_NR_CEP DECIMAL(8, 0),
    REP_NR_TEL VARCHAR(20),
    REP_NR_FAX VARCHAR(20),
    REP_NM_CONTATO VARCHAR(50),
    REP_NM_EMAIL VARCHAR(200),
    REP_NR_CNPJ VARCHAR(20),
    REP_NR_INSCREST VARCHAR(20),
    REP_DS_OBS VARCHAR(4999),
    REP_PC_COMISSAO DECIMAL(14, 2),
    REP_QT_DIASLIBERACAO DECIMAL(14, 2)
);

-- Tabela VENDA
CREATE TABLE VENDA (
    VEN_ID INT IDENTITY(1,1) PRIMARY KEY,
    VEN_NR_PEDIDO VARCHAR(10),
    CLI_ID INT,
    REP_ID INT,
    VEN_DT INT,
    VEN_ST INT,
    VEN_VL_TOTAL DECIMAL(19, 4),
    VEN_PC_COMISSAO DECIMAL(14, 2),
    VEN_DS_OBS VARCHAR(4999),
    CONSTRAINT FK_VENDA_CLIENTE FOREIGN KEY (CLI_ID) REFERENCES CLIENTE(CLI_ID),
    CONSTRAINT FK_VENDA_REPRESENTADA FOREIGN KEY (REP_ID) REFERENCES REPRESENTADA(REP_ID)
);

-- Tabela VENDA_PRODUTO
CREATE TABLE VENDA_PRODUTO (
    VEP_ID INT IDENTITY(1,1) PRIMARY KEY,
    VEN_ID INT,
    VEP_NR_ITEM INT,
    VEP_DS_PRODUTO VARCHAR(200),
    VEP_QT DECIMAL(19, 4),
    VEP_VL_TOTAL DECIMAL(19, 4),
    VEP_DT_ENTREGA DATE,
    VEP_DT_INSPECAO DATE,
    CONSTRAINT FK_VENDA_PRODUTO_VENDA FOREIGN KEY (VEN_ID) REFERENCES VENDA(VEN_ID)
);

-- Tabela VENDA_PARCELA
CREATE TABLE VENDA_PARCELA (
    VPA_ID INT IDENTITY(1,1) PRIMARY KEY,
    VEN_ID INT,
    VPA_DT_VENC DATE,
    VPA_QT_DIAS INT,
    VPA_VL DECIMAL(19, 4),
    VPA_VL_COMISSAO DECIMAL(19, 4),
    VPA_DT_RECEBIM DATE,
    VPA_FL_PAGO INT,
    CONSTRAINT FK_VENDA_PARCELA_VENDA FOREIGN KEY (VEN_ID) REFERENCES VENDA(VEN_ID)
);


-- Inserções na tabela CLIENTE
INSERT INTO CLIENTE (CLI_NM_ENDERECO, CLI_NM_BAIRRO, CLI_NM_CIDADE, CLI_NR_UF, CLI_NR_CEP, CLI_NR_TEL, CLI_NR_FAX, CLI_NM_CONTATO, CLI_NM_EMAIL, CLI_NR_CNPJ, CLI_NR_INSCREST, CLI_DS_OBS)
VALUES 
    ('Rua das Flores 123', 'Centro', 'São Paulo', 35, 01001000, '11987654321', '11987654322', 'João Silva', 'joao@empresa.com', '12345678000100', '12345678', 'Cliente ativo'),
    ('Av. Brasil 456', 'Jardim', 'Rio de Janeiro', 21, 20040010, '21976543210', '21976543211', 'Maria Oliveira', 'maria@empresa.com', '98765432000190', '98765432', 'Pagamento em dia'),
    ('Rua das Palmeiras 789', 'Bela Vista', 'Curitiba', 41, 80010020, '41965432109', '41965432108', 'Pedro Souza', 'pedro@empresa.com', '45678912000180', '45678912', 'Novo cliente'),
    ('Av. Central 321', 'Boa Viagem', 'Recife', 16, 50010030, '81954321098', '81954321097', 'Ana Costa', 'ana@empresa.com', '78912345000170', '78912345', 'Aguardando vistoria'),
    ('Rua do Sol 654', 'Ponta Negra', 'Natal', 20, 59010040, '84943210987', '84943210986', 'Carlos Lima', 'carlos@empresa.com', '32165478000160', '32165478', 'Cliente preferencial');

-- Inserções na tabela REPRESENTADA
INSERT INTO REPRESENTADA (REP_NM_ENDERECO, REP_NM_BAIRRO, REP_NM_CIDADE, REP_NR_UF, REP_NR_CEP, REP_NR_TEL, REP_NR_FAX, REP_NM_CONTATO, REP_NM_EMAIL, REP_NR_CNPJ, REP_NR_INSCREST, REP_DS_OBS, REP_PC_COMISSAO, REP_QT_DIASLIBERACAO)
VALUES 
    ('Rua Comercio 101', 'Centro', 'São Paulo', 35, 01002000, '11965432100', '11965432101', 'Lucas Mendes', 'lucas@representada.com', '11223344000199', '11223344', 'Fornece eletrônicos', 10.50, 5),
    ('Av. Industrial 202', 'Industrial', 'Rio de Janeiro', 21, 20050020, '21954321099', '21954321098', 'Fernanda Lima', 'fernanda@representada.com', '55443322000188', '55443322', 'Produtos de limpeza', 8.75, 7),
    ('Rua das Águas 303', 'Lagoa', 'Curitiba', 41, 80020030, '41943210988', '41943210987', 'Rafael Souza', 'rafael@representada.com', '66778899000177', '66778899', 'Móveis planejados', 12.00, 3),
    ('Av. Comercio 404', 'Boa Vista', 'Recife', 16, 50020040, '81932109877', '81932109876', 'Juliana Pereira', 'juliana@representada.com', '99887766000166', '99887766', 'Alimentos', 9.25, 10),
    ('Rua das Estrelas 505', 'Pajuçara', 'Maceió', 2, 57010050, '82921098765', '82921098764', 'Gustavo Almeida', 'gustavo@representada.com', '33445566000155', '33445566', 'Vestuários', 11.00, 4);

-- Inserções na tabela VENDA
INSERT INTO VENDA (VEN_NR_PEDIDO, CLI_ID, REP_ID, VEN_DT, VEN_ST, VEN_VL_TOTAL, VEN_PC_COMISSAO, VEN_DS_OBS)
VALUES 
    ('PED001', 1, 1, 20250513, 1, 5000.00, 10.50, 'Venda concluída'),
    ('PED002', 2, 2, 20250512, 0, 3000.00, 8.75, 'Aguardando aprovação'),
    ('PED003', 3, 3, 20250511, 1, 7500.00, 12.00, 'Pagamento confirmado'),
    ('PED004', 4, 4, 20250510, 0, 4500.00, 9.25, 'Em análise'),
    ('PED005', 5, 5, 20250509, 1, 6000.00, 11.00, 'Entrega agendada');

-- Inserções na tabela VENDA_PRODUTO
INSERT INTO VENDA_PRODUTO (VEN_ID, VEP_NR_ITEM, VEP_DS_PRODUTO, VEP_QT, VEP_VL_TOTAL, VEP_DT_ENTREGA, VEP_DT_INSPECAO)
VALUES 
    (1, 1, 'TV LED 50"', 2, 2000.00, '20250520', '20250518'),
    (1, 2, 'Smartphone X', 1, 3000.00, '20250520', '20250518'),
    (2, 1, 'Detergente 5L', 10, 3000.00, '20250519', '20250517'),
    (3, 1, 'Guarda-Roupa', 1, 7500.00, '20250518', '20250516'),
    (4, 1, 'Arroz 5kg', 50, 4500.00, '20250517', '20250515');

-- Inserções na tabela VENDA_PARCELA
INSERT INTO VENDA_PARCELA (VEN_ID, VPA_DT_VENC, VPA_QT_DIAS, VPA_VL, VPA_VL_COMISSAO, VPA_DT_RECEBIM, VPA_FL_PAGO)
VALUES 
    (1, '20250520', 7, 2500.00, 262.50, '20250520', 1),
    (1, '20250527', 14, 2500.00, 262.50, NULL, 0),
    (2, '20250519', 7, 3000.00, 262.50, '20250519', 1),
    (3, '20250518', 7, 7500.00, 900.00, '20250518', 1),
    (4, '20250517', 7, 4500.00, 416.25, NULL, 0);

-- Alterar a tabela CLIENTE para adicionar a coluna CLI_NM
ALTER TABLE CLIENTE
ADD CLI_NM VARCHAR(200);

-- Alterar a tabela REPRESENTADA para adicionar a coluna REP_NM
ALTER TABLE REPRESENTADA
ADD REP_NM VARCHAR(200);

-- Atualizar a tabela CLIENTE com valores para CLI_NM
UPDATE CLIENTE
SET CLI_NM = 'João Silva'
WHERE CLI_ID = 1;

UPDATE CLIENTE
SET CLI_NM = 'Maria Oliveira'
WHERE CLI_ID = 2;

UPDATE CLIENTE
SET CLI_NM = 'Pedro Souza'
WHERE CLI_ID = 3;

UPDATE CLIENTE
SET CLI_NM = 'Ana Costa'
WHERE CLI_ID = 4;

UPDATE CLIENTE
SET CLI_NM = 'Carlos Lima'
WHERE CLI_ID = 5;

-- Atualizar a tabela REPRESENTADA com valores para REP_NM
UPDATE REPRESENTADA
SET REP_NM = 'Eletrônicos LTDA'
WHERE REP_ID = 1;

UPDATE REPRESENTADA
SET REP_NM = 'Produtos Limpeza S/A'
WHERE REP_ID = 2;

UPDATE REPRESENTADA
SET REP_NM = 'Móveis Planejados ME'
WHERE REP_ID = 3;

UPDATE REPRESENTADA
SET REP_NM = 'Alimentos Recife LTDA'
WHERE REP_ID = 4;

UPDATE REPRESENTADA
SET REP_NM = 'Vestuários Maceió EIRELI'
WHERE REP_ID = 5;



-- VIEWS EXERCICIOS
-- a) Crie uma view chamada V_dados_pessoais_cliente que mostre nome, endereço completo, e dados para contato

create or alter view V_dados_pessoais_cliente
as select CLI_NM, CLI_NM_ENDERECO, CLI_NM_BAIRRO, CLI_NM_CIDADE, CLI_NR_UF, CLI_NM_CONTATO
from CLIENTE

select CLI_NM, CLI_NM_ENDERECO, CLI_NM_BAIRRO, CLI_NM_CIDADE, CLI_NR_UF, CLI_NM_CONTATO
from V_dados_pessoais_cliente

-- b) Crie uma view chamada V_vendas_parceladas que mostre as vendas realizadas, o nome do cliente e as respectivas parcelas desta venda (valor da parcela, data de vencimento e data de receimento).

create or alter view V_vendas_parceladas
as select v.VEN_ID, c.CLI_NM nome_cliente, vp.VPA_VL valor_parcela, vp.VPA_DT_VENC data_vencimento_parcela, vp.VPA_DT_RECEBIM data_recebimento_parcela
from VENDA v
	inner join CLIENTE c
	on v.CLI_ID = c.CLI_ID
	inner join VENDA_PARCELA vp
	on v.VEN_ID = vp.VEN_ID

select VEN_ID, nome_cliente, valor_parcela, data_vencimento_parcela, data_recebimento_parcela
from V_vendas_parceladas

-- c) Crie uma view chamada V_dados_representada que mostre todos os dados da tabela representada

create or alter view V_dados_representada
as select REP_ID, REP_NM_ENDERECO, REP_NM_BAIRRO, REP_NM_CIDADE, REP_NR_UF, REP_NR_CEP, REP_NR_TEL, REP_NR_FAX, REP_NM_CONTATO, REP_NM_EMAIL, REP_NR_CNPJ, REP_NR_INSCREST, REP_DS_OBS, REP_PC_COMISSAO, REP_QT_DIASLIBERACAO
from REPRESENTADA

select REP_ID, REP_NM_ENDERECO, REP_NM_BAIRRO, REP_NM_CIDADE, REP_NR_UF, REP_NR_CEP, REP_NR_TEL, REP_NR_FAX, REP_NM_CONTATO, REP_NM_EMAIL, REP_NR_CNPJ, REP_NR_INSCREST, REP_DS_OBS, REP_PC_COMISSAO, REP_QT_DIASLIBERACAO
from V_dados_representada

-- d) Faça um comando de atualização na view criada na letra C e aumente o percentual de comissão para 20%. O comando foi bem-sucedido? Por que?

update V_dados_representada
	set REP_PC_COMISSAO = (REP_PC_COMISSAO * 0.20) + REP_PC_COMISSAO

select REP_ID, REP_NM_ENDERECO, REP_NM_BAIRRO, REP_NM_CIDADE, REP_NR_UF, REP_NR_CEP, REP_NR_TEL, REP_NR_FAX, REP_NM_CONTATO, REP_NM_EMAIL, REP_NR_CNPJ, REP_NR_INSCREST, REP_DS_OBS, REP_PC_COMISSAO, REP_QT_DIASLIBERACAO
from V_dados_representada

-- e) Crie uma view chamada V_vendas_produto, que exiba as vendas e os respectivos produtos que compõem a venda

create or alter view V_vendas_produto 
as select v.VEN_ID, v.VEN_DS_OBS descricao_venda, v.VEN_VL_TOTAL total_venda, vp.VEP_DS_PRODUTO descricao_produto, vp.VEP_QT qtd_produto, vp.VEP_VL_TOTAL total
from VENDA v
	left join VENDA_PRODUTO vp
	on v.VEN_ID = vp.VEN_ID

select VEN_ID, descricao_venda, total_venda, descricao_produto, qtd_produto, total
from V_vendas_produto

-- f) Crie uma view chamada V_dados_representada1 que mostre os dados da tabela representada, exceto o REP_ID. 

create or alter view V_dados_representada1
as select REP_NM_ENDERECO, REP_NM_BAIRRO, REP_NM_CIDADE, REP_NR_UF, REP_NR_CEP, REP_NR_TEL, REP_NR_FAX, REP_NM_CONTATO, REP_NM_EMAIL, REP_NR_CNPJ, REP_NR_INSCREST, REP_DS_OBS, REP_PC_COMISSAO, REP_QT_DIASLIBERACAO
from REPRESENTADA

select REP_NM_ENDERECO, REP_NM_BAIRRO, REP_NM_CIDADE, REP_NR_UF, REP_NR_CEP, REP_NR_TEL, REP_NR_FAX, REP_NM_CONTATO, REP_NM_EMAIL, REP_NR_CNPJ, REP_NR_INSCREST, REP_DS_OBS, REP_PC_COMISSAO, REP_QT_DIASLIBERACAO
from V_dados_representada1

-- g) Faça um comando de atualização na view criada na letra F e altere a quantidade de dias para liberação para 15 dias. O comando foi bem-sucedido? Por que?

update V_dados_representada1
	set REP_QT_DIASLIBERACAO = 15

select REP_NM_ENDERECO, REP_NM_BAIRRO, REP_NM_CIDADE, REP_NR_UF, REP_NR_CEP, REP_NR_TEL, REP_NR_FAX, REP_NM_CONTATO, REP_NM_EMAIL, REP_NR_CNPJ, REP_NR_INSCREST, REP_DS_OBS, REP_PC_COMISSAO, REP_QT_DIASLIBERACAO
from V_dados_representada1