

create table tbNovela (
	codigo_novela int constraint PK_Codigo_Novela primary key identity,
	nome_novela varchar(30) constraint NN_Nome_Novela not null,
	data_primeiro_capitulo date,
	data_ultimo_capitulo date,
	horário_exibicao time
)

create table tbAtor (
	codigo_ator int constraint PK_Codigo_Ator primary key identity,
	nome_ator varchar(20) constraint NN_Nome_Ator not null,
	idade int,
	cidade_ator varchar(20),
	salario_ator real,
	sexo_ator char(1)
)

create table tbPersonagem (
	codigo_personagem int constraint PK_Codigo_Personagem primary key identity,
	nome_personagem varchar(50) constraint NN_Nome_Personagem not null,
	idade_personagem int,
	situacao_financeira_personagem varchar(20),
	codigo_ator int constraint FK_Personagem_Codigo_Ator foreign key references tbAtor(codigo_ator)
)

create table tbNovelaPersonagem (
	codigo_personagem int constraint FK_Novela_Personagem_Codigo_Personagem foreign key references tbPersonagem(codigo_personagem),
	codigo_novela int constraint FK_Novela_Personagem_Codigo_Novela foreign key references tbNovela(codigo_novela),
	constraint PK_Codigo_Personagem_Codigo_Novela primary key(codigo_personagem, codigo_novela)
)

create table tbCapitulos (
	codigo_capitulo int constraint PK_Codigo_Capitulo primary key identity,
	nome_capitulo varchar(50) constraint NN_Nome_Capitulo not null,
	data_exibicao_capitulo date,
	codigo_novela int constraint FK_Capitulos_Codigo_Novela foreign key references tbNovela(codigo_novela)
)


-- INSERTS use BDNovela

INSERT INTO tbAtor (nome_ator, idade, cidade_ator, salario_ator, sexo_ator)
VALUES 
    ('Ana Silva', 30, 'São Paulo', 5000.00, 'F'),
    ('João Santos', 45, 'Rio de Janeiro', 7500.00, 'M'),
    ('Maria Oliveira', 28, 'Belo Horizonte', 6000.00, 'F');


INSERT INTO tbNovela (nome_novela, data_primeiro_capitulo, data_ultimo_capitulo, horário_exibicao)
VALUES 
    ('Amor Eterno', '2025-01-01', '2025-06-30', '20:00:00'),
    ('Caminhos do Coração', '2025-02-01', '2025-08-15', '21:00:00'),
    ('Sol Nascente', '2025-03-01', '2025-09-30', '18:30:00');


INSERT INTO tbPersonagem (nome_personagem, idade_personagem, situacao_financeira_personagem, codigo_ator)
VALUES 
    ('Clara Mendes', 25, 'Rica', 1), -- Ana Silva
    ('Pedro Almeida', 40, 'Classe Média', 2), -- João Santos
    ('Sofia Ribeiro', 22, 'Pobre', 3); -- Maria Oliveira


	INSERT INTO tbNovelaPersonagem (codigo_personagem, codigo_novela)
VALUES 
    (1, 1), -- Clara Mendes em Amor Eterno
    (2, 2), -- Pedro Almeida em Caminhos do Coração
    (3, 3); -- Sofia Ribeiro em Sol Nascente


INSERT INTO tbCapitulos (nome_capitulo, data_exibicao_capitulo, codigo_novela)
VALUES 
    ('Um Novo Começo', '2025-01-01', 1), -- Amor Eterno
    ('Segredos Revelados', '2025-02-01', 2), -- Caminhos do Coração
    ('Primeiros Raios', '2025-03-01', 3); -- Sol Nascente