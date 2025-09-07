create table projeto (
	numProjeto int constraint PK_NumProjeto primary key,
	nome varchar(255) constraint NN_NomeProjeto not null,
	localizacao varchar(50) constraint NN_LocalizacaoProjeto not null
)	

create table empregado (
	rg int constraint PK_RgEmpregado primary key,
	cpf int constraint NN_CpfEmpregado not null constraint UN_Cpf unique,
	nome varchar(255) constraint NN_NomeEmpregado not null,
	rgSupervisor int constraint FK_RgSupervisorEmpregado foreign key references empregado(rg),
	salario money constraint NN_SalarioEmpregado not null
)

create table departamento (
	numDepto int constraint PK_NumDepto primary key,
	nome varchar(255) constraint NN_NomeDepartamento not null,
	rgGerente int constraint FK_RgGerente foreign key references empregado(rg)
)

create table dependentes (
	rgResponsavel int constraint FK_RgResponsavel foreign key references empregado(rg),
	nomeDependente varchar(255) constraint UN_NomeDependente unique,
	cpfDependente int constraint PK_CpfDependente primary key,
	dtNascimento date constraint NN_DtNascimentoDependente not null,
	relacao varchar(50) constraint NN_RelacaoDependente not null,
	sexo varchar(50) constraint NN_SexoDependente not null
)

create table departamentoProjeto (
	numDepto int,
	numProjeto int,
	constraint PK_DepartamentoProjeto primary key(numDepto, numProjeto),
	constraint FK_DP_NumDepto foreign key(numDepto) references departamento(numDepto),
	constraint FK_DP_NumProjeto foreign key(numProjeto) references projeto(numProjeto)
)

create table empregadoProjeto (
	rgEmpregado int,
	numProjeto int,
	constraint PK_EmpregadoProjeto primary key(rgEmpregado, numProjeto),
	constraint FK_EP_RgEmpregado foreign key(rgEmpregado) references empregado(rg),
	constraint FK_EP_NumProjeto foreign key(numProjeto) references projeto(numProjeto)
)

alter table 