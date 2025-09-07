create database BD_Views
use BD_Views

create table Cliente (
	Cod_Cliente int primary key identity(1, 1), 
	Nome varchar(150), 
	RG char(12), 
	CPF char(12), 
	Salário money,
	Estado_Civil char, 
	Sexo char
)

insert into Cliente
values('Zequinha','77777777',' 77777777 ',17000.00,'C','M');
insert into Cliente
values('Joaozinho','55555555',' 55555555',3000.00,'S','M');
insert into Cliente
values('Mariazinha','33333333',' 33333333 ',18000.00,'C','F');
insert into Cliente
values('Terezinha','99999999','99999999',5000.00,'S','F');

-- EXERCICIOS
--1) Crie uma view chamada v_Cliente para a tabela Cliente, ocultando o atributo salario.

create or alter view v_Cliente as 
select Cod_Cliente, Nome, RG, CPF, Estado_Civil, Sexo
from Cliente

--2) Consulte a view que você acabou de criar.

select Cod_Cliente, Nome, RG, CPF, Estado_Civil, Sexo
from v_Cliente

--3) Elabore uma consulta em v_Cliente que retorne todos os clientes solteiros e do sexo masculino.

select Cod_Cliente, Nome, Estado_Civil, Sexo
from v_Cliente
where Estado_Civil = 'S' and Sexo = 'M'

--4) Elabore uma consulta em v_Cliente que retorne todos os clientes com renda maior que R$13.500.

select vc.Cod_Cliente, vc.Nome, c.Salário
from v_Cliente vc
	inner join Cliente c
	on vc.Cod_Cliente = c.Cod_Cliente
where c.Salário > 13500

--5) Elabore uma consulta em v_Cliente que retorne a quantidade de homens casados.

select COUNT(vc.Cod_Cliente) as qtd_homens_casados
from v_Cliente vc
where vc.Estado_Civil = 'C' and vc.Sexo = 'M'

--6) Atualize o estado civil da V_cliente se o codcliente = 1

update v_Cliente
set Estado_Civil = 'C'
where Cod_Cliente = 1