DROP DATABASE IF EXISTS BDLojaInstrumentosMusicais

use master

create database BDLojaInstrumentosMusicais
use BDLojaInstrumentosMusicais

-- Criação das tabelas para o Projeto Loja de Instrumentos Musicais

CREATE TABLE Pais (
    id_pais INT IDENTITY(1,1) CONSTRAINT PK_Pais PRIMARY KEY,
    nome VARCHAR(100) CONSTRAINT NN_Nome_Pais NOT NULL,
    sigla CHAR(3) CONSTRAINT NN_Sigla_Pais NOT NULL
);

CREATE TABLE Estado (
    id_estado INT IDENTITY(1,1) CONSTRAINT PK_Estado PRIMARY KEY,
    nome VARCHAR(50) CONSTRAINT NN_Nome_Estado NOT NULL,
    sigla CHAR(2) CONSTRAINT NN_Sigla_Estado NOT NULL,
	id_pais INT CONSTRAINT FK_Pais_Estado REFERENCES Pais(id_pais) NOT NULL
);

CREATE TABLE Cidade (
    id_cidade INT IDENTITY(1,1) CONSTRAINT PK_Cidade PRIMARY KEY,
    nome VARCHAR(100) CONSTRAINT NN_Nome_Cidade NOT NULL,
    id_estado INT CONSTRAINT FK_Estado_Cidade REFERENCES Estado(id_estado) NOT NULL
);

CREATE TABLE Endereco (
    id_endereco INT IDENTITY(1,1) CONSTRAINT PK_Endereco PRIMARY KEY,
    logradouro VARCHAR(100) CONSTRAINT NN_Logradouro_Endereco NOT NULL,
    numero VARCHAR(10) CONSTRAINT NN_Numero_Endereco NOT NULL,
    complemento VARCHAR(50),
    bairro VARCHAR(50) CONSTRAINT NN_Bairro_Endereco NOT NULL,
    cep VARCHAR(10) CONSTRAINT NN_CEP_Endereco NOT NULL,
    id_cidade INT CONSTRAINT FK_Cidade_Endereco REFERENCES Cidade(id_cidade) NOT NULL
);

CREATE TABLE Cargo (
    id_cargo INT IDENTITY(1,1) CONSTRAINT PK_Cargo PRIMARY KEY,
    nome VARCHAR(100) CONSTRAINT NN_Nome_Cargo NOT NULL,
    descricao VARCHAR(1000),
    nivel INT CONSTRAINT NN_Nivel_Cargo NOT NULL,
    ativo BIT CONSTRAINT NN_Ativo_Cargo NOT NULL
);

CREATE TABLE Cliente (
    id_cliente INT IDENTITY(1,1) CONSTRAINT PK_Cliente PRIMARY KEY,
    nome VARCHAR(255) CONSTRAINT NN_Nome_Cliente NOT NULL,
    cpf CHAR(11) CONSTRAINT UN_CPF_Cliente UNIQUE,
    email VARCHAR(100),
    telefone VARCHAR(20),
    data_nascimento DATE,
    data_cadastro DATETIME CONSTRAINT NN_DataCadastro_Cliente NOT NULL,
    id_endereco INT CONSTRAINT FK_Endereco_Cliente REFERENCES Endereco(id_endereco)
);

CREATE TABLE Funcionario (
    id_funcionario INT IDENTITY(1,1) CONSTRAINT PK_Funcionario PRIMARY KEY,
    nome VARCHAR(100) CONSTRAINT NN_Nome_Funcionario NOT NULL,
    cpf CHAR(11) CONSTRAINT UN_CPF_Funcionario UNIQUE CONSTRAINT NN_Cpf_Funcionario NOT NULL,
    email VARCHAR(100),
    telefone VARCHAR(20),
    data_admissao DATE CONSTRAINT NN_DataAdmissao_Funcionario NOT NULL,
    salario DECIMAL(10,2) CONSTRAINT NN_Salario_Funcionario NOT NULL,
    login VARCHAR(150) CONSTRAINT UN_Login_Funcionario UNIQUE CONSTRAINT NN_Login_Funcionario NOT NULL,
    senha VARCHAR(100) CONSTRAINT NN_Senha_Funcionario NOT NULL,
    id_cargo INT CONSTRAINT FK_Cargo_Funcionario REFERENCES Cargo(id_cargo) CONSTRAINT NN_Cargo_Funcionario NOT NULL,
    id_endereco INT CONSTRAINT FK_Endereco_Funcionario REFERENCES Endereco(id_endereco)
);

CREATE TABLE Fornecedor (
    id_fornecedor INT IDENTITY(1,1) CONSTRAINT PK_Fornecedor PRIMARY KEY,
    nome_fantasia VARCHAR(100) CONSTRAINT NN_NomeFantasia_Fornecedor NOT NULL,
    razao_social VARCHAR(150) CONSTRAINT NN_RazaoSocial_Fornecedor NOT NULL,
    cnpj CHAR(14) CONSTRAINT UN_CNPJ_Fornecedor UNIQUE CONSTRAINT NN_Cnpj_Fornecedor NOT NULL,
    telefone VARCHAR(20),
    email VARCHAR(100),
    nome_representante VARCHAR(255),
    id_endereco INT CONSTRAINT FK_Endereco_Fornecedor REFERENCES Endereco(id_endereco)
);

CREATE TABLE TipoProduto (
    id_tipo_produto INT IDENTITY(1,1) CONSTRAINT PK_TipoProduto PRIMARY KEY,
    nome VARCHAR(100) CONSTRAINT NN_Nome_TipoProduto NOT NULL
);

CREATE TABLE Marca (
    id_marca INT IDENTITY(1,1) CONSTRAINT PK_Marca PRIMARY KEY,
    nome VARCHAR(100) CONSTRAINT NN_Nome_Marca NOT NULL
);

CREATE TABLE Produto (
    id_produto INT IDENTITY(1,1) CONSTRAINT PK_Produto PRIMARY KEY,
    nome VARCHAR(100) CONSTRAINT NN_Nome_Produto NOT NULL,
    descricao VARCHAR(1000),
    preco_venda DECIMAL(10,2) CONSTRAINT NN_PrecoVenda_Produto NOT NULL,
    preco_custo DECIMAL(10,2) CONSTRAINT NN_PrecoCusto_Produto NOT NULL,
    garantia_meses INT,
    id_tipo_produto INT CONSTRAINT FK_TipoProduto_Produto REFERENCES TipoProduto(id_tipo_produto) CONSTRAINT NN_TipoProduto_Produto NOT NULL,
    id_marca INT CONSTRAINT FK_Marca_Produto REFERENCES Marca(id_marca) CONSTRAINT NN_Marca_Produto NOT NULL,
	ativo BIT CONSTRAINT NN_Ativo_Produto NOT NULL
);

CREATE TABLE FormaPagamento (
    id_forma_pagamento INT IDENTITY(1,1) CONSTRAINT PK_FormaPagamento PRIMARY KEY,
    nome VARCHAR(100) CONSTRAINT NN_Nome_FormaPagamento NOT NULL
);

CREATE TABLE StatusVenda (
    id_status_venda INT IDENTITY(1,1) CONSTRAINT PK_StatusVenda PRIMARY KEY,
    nome VARCHAR(100) CONSTRAINT NN_Nome_StatusVenda NOT NULL
);

CREATE TABLE StatusCompra (
    id_status_compra INT IDENTITY(1,1) CONSTRAINT PK_StatusCompra PRIMARY KEY,
    nome VARCHAR(100) CONSTRAINT NN_Nome_StatusCompra NOT NULL
);

CREATE TABLE StatusGarantia (
    id_status_garantia INT IDENTITY(1,1) CONSTRAINT PK_StatusGarantia PRIMARY KEY,
    nome VARCHAR(100) CONSTRAINT NN_Nome_StatusGarantia NOT NULL
);

CREATE TABLE Venda (
    id_venda INT IDENTITY(1,1) CONSTRAINT PK_Venda PRIMARY KEY,
    data_hora DATETIME CONSTRAINT NN_DataHora_Venda NOT NULL,
    valor_total DECIMAL(10,2) CONSTRAINT NN_ValorTotal_Venda NOT NULL,
    id_status_venda INT CONSTRAINT FK_StatusVenda_Venda REFERENCES StatusVenda(id_status_venda) CONSTRAINT NN_IdStatusVenda_Venda NOT NULL,
    id_cliente INT CONSTRAINT FK_Cliente_Venda REFERENCES Cliente(id_cliente) CONSTRAINT NN_IdCliente_Venda NOT NULL,
    id_funcionario INT CONSTRAINT FK_Funcionario_Venda REFERENCES Funcionario(id_funcionario) CONSTRAINT NN_Funcionario_Venda NOT NULL,
    id_forma_pagamento INT CONSTRAINT FK_FormaPagamento_Venda REFERENCES FormaPagamento(id_forma_pagamento) CONSTRAINT NN_FormaPagamento_Venda NOT NULL
);

CREATE TABLE Compra (
    id_compra INT IDENTITY(1,1) CONSTRAINT PK_Compra PRIMARY KEY,
    data_hora DATETIME CONSTRAINT NN_DataHora_Compra NOT NULL,
    valor_total DECIMAL(10,2) CONSTRAINT NN_ValorTotal_Compra NOT NULL,
    id_status_compra INT CONSTRAINT FK_StatusCompra_Compra REFERENCES StatusCompra(id_status_compra) CONSTRAINT NN_StatusCompra_Compra NOT NULL,
    id_funcionario INT CONSTRAINT FK_Funcionario_Compra REFERENCES Funcionario(id_funcionario) CONSTRAINT NN_IdFuncionario_Compra NOT NULL,
    id_fornecedor INT CONSTRAINT FK_Fornecedor_Compra REFERENCES Fornecedor(id_fornecedor) CONSTRAINT NN_Fornecedor_Compra NOT NULL,
	id_forma_pagamento INT CONSTRAINT FK_FormaPagamento_Compra REFERENCES FormaPagamento(id_forma_pagamento) CONSTRAINT NN_FormaPagamento_Compra NOT NULL
);

CREATE TABLE Garantia (
    id_garantia INT IDENTITY(1,1) CONSTRAINT PK_Garantia PRIMARY KEY,
    data_solicitacao DATE CONSTRAINT NN_DataSolicitacao_Garantia NOT NULL,
    data_hora_conclusao DATETIME,
    descricao_problema VARCHAR(1000),
	descricao_solucao VARCHAR(1000),
    id_status_garantia INT CONSTRAINT FK_StatusGarantia_Garantia REFERENCES StatusGarantia(id_status_garantia) CONSTRAINT NN_StatusGarantia_Garantia NOT NULL,
    id_produto INT CONSTRAINT FK_Produto_Garantia REFERENCES Produto(id_produto) CONSTRAINT NN_IdProduto_Garantia NOT NULL,
    id_venda INT CONSTRAINT FK_Venda_Garantia REFERENCES Venda(id_venda) CONSTRAINT NN_IdVenda_Garantia NOT NULL
);

CREATE TABLE Estoque_Movimentacao (
    id_movimentacao_estoque INT IDENTITY(1,1) CONSTRAINT PK_Estoque_Movimentacao PRIMARY KEY,
	tipo_movimentacao CHAR(1) CHECK (tipo_movimentacao IN ('E', 'S')) CONSTRAINT NN_tipoMovimentacao_Estoque NOT NULL, -- 'ENTRADA' | 'SAIDA'
    quantidade_anterior INT CONSTRAINT NN_QtdAnterior_Estoque NOT NULL,
    quantidade_atual INT CONSTRAINT NN_QtdAtual_Estoque NOT NULL,
    quantidade_movimentada INT CONSTRAINT NN_QtdMovimentada_Estoque NOT NULL,
    data_hora DATETIME CONSTRAINT NN_DataHora_Estoque NOT NULL DEFAULT GETDATE(),
    valor_unitario DECIMAL(10,2) CONSTRAINT NN_ValorUnitario_Estoque NOT NULL,
    id_compra INT CONSTRAINT FK_Compra_Estoque REFERENCES Compra(id_compra),
	id_venda INT CONSTRAINT FK_Venda_Estoque REFERENCES Venda(id_venda),
	id_produto INT CONSTRAINT FK_Produto_Estoque REFERENCES Produto(id_produto) CONSTRAINT NN_IdProduto_Estoque NOT NULL
); 


-- INSERÇÕES NAS TABELAS
-- Inserções na tabela Pais
INSERT INTO Pais (nome, sigla) VALUES
    ('Brasil', 'BR'),
    ('Argentina', 'AR'),
    ('Uruguai', 'UY'),
    ('Paraguai', 'PY');

select id_pais, nome, sigla from Pais

-- Inserções na tabela Estado
INSERT INTO Estado (nome, sigla, id_pais) VALUES
    ('São Paulo', 'SP', 1),
    ('Rio de Janeiro', 'RJ', 1),
    ('Buenos Aires', 'BA', 2),
    ('Montevidéu', 'MV', 3);

select id_estado, nome, sigla, id_pais from Estado

-- Inserções na tabela Cidade
INSERT INTO Cidade (nome, id_estado) VALUES
    ('São Paulo', 1),
    ('Campinas', 1),
    ('Rio de Janeiro', 2),
    ('Niterói', 2);

select id_cidade, nome, id_estado from Cidade

-- Inserções na tabela Endereco
INSERT INTO Endereco (logradouro, numero, complemento, bairro, cep, id_cidade) VALUES
    ('Av. Paulista', '1000', 'Apto 101', 'Bela Vista', '01310-100', 1),
    ('Rua XV de Novembro', '500', NULL, 'Centro', '13010-150', 2),
    ('Copacabana', '200', 'Bloco B', 'Copacabana', '22031-011', 3),
    ('Av. Atlântica', '300', NULL, 'Ipanema', '22410-060', 4);

select id_endereco, logradouro, numero, complemento, bairro, cep, id_cidade from Endereco

-- Inserções na tabela Cargo
INSERT INTO Cargo (nome, descricao, nivel, ativo) VALUES
    ('Gerente', 'Responsável pela gestão da equipe', 3, 1),
    ('Vendedor', 'Atendimento ao cliente e vendas', 1, 1),
    ('Analista', 'Análise de dados e relatórios', 2, 1),
    ('Estagiário', 'Suporte às atividades operacionais', 0, 1);

select id_cargo, nome, descricao, nivel, ativo from Cargo

-- Inserções na tabela Cliente
INSERT INTO Cliente (nome, cpf, email, telefone, data_nascimento, data_cadastro, id_endereco) VALUES
    ('João Silva', '12345678901', 'joao@email.com', '11987654321', '1990-05-15', GETDATE(), 1),
    ('Maria Oliveira', '98765432109', 'maria@email.com', '11976543210', '1985-08-22', GETDATE(), 2),
    ('Pedro Santos', '45678912345', 'pedro@email.com', '21987654321', '1992-03-10', GETDATE(), 3),
    ('Ana Costa', '32165498765', 'ana@email.com', '21976543210', '1988-11-30', GETDATE(), 4);

select id_cliente, nome, cpf, email, telefone, data_nascimento, data_cadastro, id_endereco from Cliente

-- Inserções na tabela Funcionario
INSERT INTO Funcionario (nome, cpf, email, telefone, data_admissao, salario, login, senha, id_cargo, id_endereco) VALUES
    ('Carlos Almeida', '11122233344', 'carlos@email.com', '11912345678', '2023-01-10', 5000.00, 'carlos.almeida', 'senha123', 1, 1),
    ('Fernanda Lima', '22233344455', 'fernanda@email.com', '11923456789', '2022-06-15', 3000.00, 'fernanda.lima', 'senha456', 2, 2),
    ('Rafael Souza', '33344455566', 'rafael@email.com', '21912345678', '2021-09-01', 4000.00, 'rafael.souza', 'senha789', 3, 3),
    ('Juliana Pereira', '44455566677', 'juliana@email.com', '21923456789', '2024-02-20', 2000.00, 'juliana.pereira', 'senha101', 4, 4);

select id_funcionario, nome, cpf, email, telefone, data_admissao, salario, login, senha, id_cargo, id_endereco from Funcionario

-- Inserções na tabela FormaPagamento
INSERT INTO FormaPagamento (nome) VALUES
    ('Cartão de Crédito'),
    ('Cartão de Débito'),
    ('Dinheiro'),
    ('Pix');

select id_forma_pagamento, nome from FormaPagamento

-- Inserções na tabela StatusVenda
INSERT INTO StatusVenda (nome) VALUES
    ('Pendente'),
    ('Concluída'),
    ('Cancelada'),
    ('Em Andamento');

select id_status_venda, nome from StatusVenda

-- Inserções na tabela StatusCompra
INSERT INTO StatusCompra (nome) VALUES
    ('Pendente'),
    ('Concluída'),
    ('Cancelada'),
    ('Recebida');

select id_status_compra, nome from StatusCompra

-- Inserções na tabela StatusGarantia
INSERT INTO StatusGarantia (nome) VALUES
    ('Aberta'),
    ('Em Análise'),
    ('Concluída'),
    ('Rejeitada');

select id_status_garantia, nome from StatusGarantia

-- Inserções na tabela Fornecedor
INSERT INTO Fornecedor (nome_fantasia, razao_social, cnpj, telefone, email, nome_representante, id_endereco) VALUES
('MusicSupply', 'MusicSupply Distribuidora LTDA', '12345678000195', '11999999999', 'contact@musicsupply.com', 'Lucas Mendes', 1),
('SoundWave', 'SoundWave Importadora S/A', '98765432000188', '11988888888', 'sales@soundwave.com', 'Mariana Costa', 2),
('RhythmImports', 'RhythmImports LTDA', '45678912000177', '21977777777', 'info@rhythmimports.com', 'Ricardo Lima', 3),
('MelodyDistrib', 'MelodyDistrib EIRELI', '32165498000166', '21966666666', 'support@melodydistrib.com', 'Clara Almeida', 4);

select id_fornecedor, nome_fantasia, razao_social, cnpj, telefone, email, nome_representante, id_endereco from Fornecedor

-- Inserções na tabela TipoProduto
INSERT INTO TipoProduto (nome) VALUES
    ('Instrumentos de Corda'),
    ('Instrumentos de Sopro'),
    ('Percussão'),
    ('Acessórios Musicais');

select id_tipo_produto, nome from TipoProduto

-- Inserções na tabela Marca

INSERT INTO Marca (nome) VALUES
    ('Fender'),
    ('Yamaha'),
    ('Roland'),
    ('Gibson');

select id_marca, nome from Marca

-- Inserções na tabela Produto

INSERT INTO Produto (nome, descricao, preco_venda, preco_custo, garantia_meses, id_tipo_produto, id_marca, ativo) VALUES
    ('Guitarra Elétrica Fender Stratocaster', 'Guitarra elétrica com corpo em alder e captadores single-coil', 7500.00, 5500.00, 12, 1, 1, 1),
    ('Saxofone Alto Yamaha YAS-280', 'Saxofone alto com acabamento laqueado', 8500.00, 6500.00, 12, 2, 2, 1),
    ('Bateria Eletrônica Roland TD-07', 'Bateria eletrônica com pads sensíveis e módulo de som', 6000.00, 4500.00, 24, 3, 3, 1),
    ('Cabo P10 Fender 3m', 'Cabo P10 para instrumentos musicais, 3 metros', 150.00, 90.00, 6, 4, 1, 1);

select id_produto, nome, descricao, preco_venda, preco_custo, garantia_meses, id_tipo_produto, id_marca, ativo from Produto

-- Inserções na tabela Compra

INSERT INTO Compra (data_hora, valor_total, id_status_compra, id_funcionario, id_fornecedor, id_forma_pagamento) VALUES
    (CONVERT(DATETIME, '2025-06-24 09:00:00', 120), 5500.00, 2, 1, 1, 4),
    (CONVERT(DATETIME, '2025-06-24 10:30:00', 120), 6500.00, 4, 2, 2, 1),
    (CONVERT(DATETIME, '2025-06-24 12:00:00', 120), 4500.00, 1, 3, 3, 3),
    (CONVERT(DATETIME, '2025-06-24 15:15:00', 120), 90.00, 2, 4, 4, 2);

select id_compra, data_hora, valor_total, id_status_compra, id_funcionario, id_fornecedor, id_forma_pagamento from Compra

-- Inserções na tabela Venda

INSERT INTO Venda (data_hora, valor_total, id_status_venda, id_cliente, id_funcionario, id_forma_pagamento) VALUES
    (CONVERT(DATETIME, '2025-06-24 10:00:00', 120), 7500.00, 2, 1, 1, 1),
    (CONVERT(DATETIME, '2025-06-24 11:30:00', 120), 150.00, 2, 2, 2, 3),
    (CONVERT(DATETIME, '2025-06-24 14:00:00', 120), 8500.00, 1, 3, 3, 4),
    (CONVERT(DATETIME, '2025-06-24 16:45:00', 120), 6000.00, 4, 4, 4, 2),
    (CONVERT(DATETIME, '2025-06-25 09:30:00', 120), 150.00, 2, 1, 1, 1);

select id_venda, data_hora, valor_total, id_status_venda, id_cliente, id_funcionario, id_forma_pagamento from Venda

-- Inserções na tabela Garantia
INSERT INTO Garantia (data_solicitacao, data_hora_conclusao, descricao_problema, descricao_solucao, id_status_garantia, id_produto, id_venda) VALUES
    (CONVERT(DATE, '2025-06-24', 120), NULL, 'Guitarra com problema no captador', NULL, 1, 1, 1),
    (CONVERT(DATE, '2025-06-24', 120), CONVERT(DATETIME, '2025-06-24 15:00:00', 120), 'Cabo P10 com mal contato', 'Trocado por novo', 3, 4, 2),
    (CONVERT(DATE, '2025-06-24', 120), NULL, 'Saxofone com chave desalinhada', NULL, 2, 2, 3),
    (CONVERT(DATE, '2025-06-24', 120), CONVERT(DATETIME, '2025-06-24 17:00:00', 120), 'Bateria com pad não funcionando', 'Pad substituído', 3, 3, 4);

select id_garantia, data_solicitacao, data_hora_conclusao, descricao_problema, descricao_solucao, id_status_garantia, id_produto, id_venda from Garantia

-- Inserções na tabela Estoque_Movimentacao
INSERT INTO Estoque_Movimentacao (tipo_movimentacao, quantidade_anterior, quantidade_atual, quantidade_movimentada, data_hora, valor_unitario, id_compra, id_venda, id_produto) VALUES
    -- Compra 2: Guitarra
    ('E', 0, 2, 2, CONVERT(DATETIME, '2025-06-24 09:00:00', 120), 5500.00, 1, NULL, 1),
    -- Venda 1: Guitarra
    ('S', 2, 1, 1, CONVERT(DATETIME, '2025-06-24 10:00:00', 120), 5500.00, NULL, 1, 1),
    -- Compra 2: Saxofone
    ('E', 0, 1, 1, CONVERT(DATETIME, '2025-06-24 10:30:00', 120), 6500.00, 2, NULL, 2),
    -- Venda 2: Cabo P10
    ('S', 0, 0, 1, CONVERT(DATETIME, '2025-06-24 11:30:00', 120), 90.00, NULL, 2, 4),
    -- Compra 3: Bateria
    ('E', 0, 1, 1, CONVERT(DATETIME, '2025-06-24 12:00:00', 120), 4500.00, 3, NULL, 3),
    -- Venda 3: Saxofone
    ('S', 1, 0, 1, CONVERT(DATETIME, '2025-06-24 14:00:00', 120), 6500.00, NULL, 3, 2),
    -- Compra 4: Cabo P10
    ('E', 0, 1, 1, CONVERT(DATETIME, '2025-06-24 15:15:00', 120), 90.00, 4, NULL, 4),
    -- Venda 4: Bateria
    ('S', 1, 0, 1, CONVERT(DATETIME, '2025-06-24 16:45:00', 120), 4500.00, NULL, 4, 3),
    -- Venda 5: Cabo P10
    ('S', 1, 0, 1, CONVERT(DATETIME, '2025-06-25 09:30:00', 120), 90.00, NULL, 5, 4);


select id_movimentacao_estoque, tipo_movimentacao, quantidade_anterior, quantidade_atual, quantidade_movimentada, data_hora, valor_unitario, id_compra, id_venda, id_produto from Estoque_Movimentacao



select em.id_movimentacao_estoque,
    p.nome AS nome_produto,
    CASE em.tipo_movimentacao
        WHEN 'E' THEN 'Entrada'
        WHEN 'S' THEN 'Saída'
    END AS tipo_movimentacao,
    em.quantidade_anterior,
    em.quantidade_movimentada,
    em.quantidade_atual,
    em.valor_unitario,
    em.data_hora,
    
    f.nome_fantasia AS fornecedor,
    func.nome AS funcionario_responsavel,
    
    v.id_venda,
    c.id_compra
from Estoque_Movimentacao em
	left join Produto p
	on em.id_produto = p.id_produto

	left join Compra c
	on em.id_compra = c.id_compra
	
	left join Fornecedor f
	on c.id_fornecedor = f.id_fornecedor

	left join Venda v
	on em.id_venda = v.id_venda

	left join Funcionario func
	on func.id_funcionario = ISNULL(c.id_funcionario, v.id_funcionario)
