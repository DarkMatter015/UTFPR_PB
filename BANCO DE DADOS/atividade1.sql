create table estado (
	codEstado int constraint PK_CodEstado primary key identity(1,1),
	nome varchar(50) constraint NN_NomeEstado not null
)

create table cidade (
	codCidade int constraint PK_CodCidade primary key identity(1,1),
	nome varchar(50) constraint NN_NomeCidade not null,
	codEstado int constraint FK_CodEstadoCidade foreign key references estado(codEstado)
)


create table tipo_conta (
	codTipo int constraint PK_CodTipoConta primary key identity(1,1),
	nome varchar(50) constraint NN_NomeTipoConta not null
)

create table tipo_emprestimo (
	codTipo int constraint PK_CodTipoEmprestimo primary key identity(1,1),
	nome varchar(50) constraint NN_NomeTipoEmprestimo not null
)

create table bancos (
	codBanco int constraint PK_CodBanco primary key identity(1,1),
	nome varchar(150) constraint NN_NomeBanco not null,
	rua varchar(150) constraint NN_RuaBanco not null,
	numero int constraint NN_NumeroBanco not null,
	bairro varchar(150) constraint NN_BairroBanco not null,
	complemento varchar(150),
	codCidade int constraint FK_CodCidadeBanco foreign key references cidade(codCidade)
)

create table agencia (
	numAgencia int constraint PK_NumAgencia primary key identity(1,1),
	rua varchar(150) constraint NN_RuaAgencia not null,
	numero int constraint NN_NumeroAgencia not null,
	bairro varchar(150) constraint NN_BairroAgencia not null,
	complemento varchar(150),
	codCidade int constraint FK_CodCidadeAgencia foreign key references cidade(codCidade),
	codBanco int constraint FK_CodBancoAgencia foreign key references bancos(codBanco)
)

create table conta (
	numConta int constraint PK_NumConta primary key identity(1,1),
	saldo money constraint NN_SaldoConta not null,
	codTipo int constraint FK_CodTipoConta foreign key references tipo_conta(codTipo),
	numAgencia int constraint FK_NumAgenciaConta foreign key references agencia(numAgencia)
)

create table emprestimos (
	numEmp int constraint PK_NumEmp primary key identity(1,1),
	quantia int constraint NN_QuantiaEmprestimos not null,
	codTipo int constraint FK_CodTipoEmprestimos foreign key references tipo_emprestimo(codTipo),
	numAgencia int constraint FK_NumAgenciaEmprestimos foreign key references agencia(numAgencia)
)

create table clientes (
	cpf int constraint PK_Cpf primary key,
	nome varchar(255) constraint NN_NomeClientes not null,
	rua varchar(150) constraint NN_RuaClientes not null,
	numero int constraint NN_NumeroClientes not null,
	bairro varchar(150) constraint NN_BairroClientes not null,
	complemento varchar(150),
	codCidade int constraint FK_CodCidadeClientes foreign key references cidade(codCidade)
)

create table telefone (
	codTelefone int constraint PK_CodTelefone primary key,
	cpf int constraint FK_CpfTelefone foreign key references clientes(cpf),
	ddd numeric(2) constraint NN_DddTelefone not null,
	numero numeric(12) constraint NN_NumeroTelefone not null
)

create table contaCliente (
	numConta int not null,
	cpf int not null,
	constraint PK_ContaCliente primary key(numConta, cpf),
	constraint FK_CC_NumConta foreign key(numConta) references conta(numConta),
	constraint FK_CC_Cpf foreign key(cpf) references clientes(cpf)
)