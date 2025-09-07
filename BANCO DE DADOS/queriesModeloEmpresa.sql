use BDModeloEmpresa
-- a) Selecione todos os campos da tabela empregados ordenados por RG em ordem decrescente.
select e.rg, e.nome, e.cpf, e.departamento, e.rgsupervisor, e.salario
from empregado e
order by rg desc

-- b) Selecione o nome de todos os empregados e o nome, a data de nascimento e a relação dos dependentes ordenados por nome dependente.
select e.nome, d.nomeDependente, d.dtNascimento, d.relacao
from empregado e
	left join dependente d
	on e.rg = d.rgresponsavel
order by d.nomeDependente

-- c) Indique quantos empregados existem por departamento.
select d.nome, count(e.rg) as qtdEmpregados
from empregado e
	inner join departamento d
	on e.departamento = d.numero
group by d.nome

-- d) Indique quantos projetos existem por departamento.
select d.numero, d.nome, count(dp.NUMERODEPARTAMENTO) as nProjetos
from departamento d
	left join departamentoprojeto dp
	on d.numero = dp.NUMERODEPARTAMENTO
group by d.numero, d.nome

select * from departamentoprojeto

-- e) Quais são os empregados que não participam de nenhum projeto?
select e.nome
from EMPREGADO e
	left join empregadoprojeto ep
	on e.RG = ep.RGEMPREGADO
where ep.NUMEROPROJETO is null

-- f) Quais são os empregados que não tem dependentes?
select e.nome
from empregado e
	left join DEPENDENTE d
	on e.RG = d.RGRESPONSAVEL
where d.RGRESPONSAVEL is null


-- g) Qual(is) o(s) empregado(s) que não tem supervisor?
--select e.nome
--from EMPREGADO e
	--left join EMPREGADO e1
	--on e.RG = e1.RG
--where e1.RGSUPERVISOR is null
select e.nome 
from empregado e 
where e.RGSUPERVISOR is null

-- h) Quais são os empregados do departamento 1?
select e.nome
from EMPREGADO e
where e.DEPARTAMENTO = 1

-- i) Quais são os dependentes do Fernando?
select d.NOMEDEPENDENTE
from DEPENDENTE d
	inner join EMPREGADO e
	on d.RGRESPONSAVEL = e.RG
where e.RG = (select rg from EMPREGADO where NOME = 'Fernando')

-- j) Quantos dependentes do sexo feminino?
select count(d.sexo) as nFeminino
from DEPENDENTE d
where d.SEXO = 'F'

-- k) Quantos dependentes tem mais que 15 anos?
select count(d.nomedependente) as n_dependente
from DEPENDENTE d
where DATEDIFF(year, d.DTNASCIMENTO, GETDATE()) > 15

-- l) Quem é o responsável pela Andreia?
select e.nome
from EMPREGADO e
	inner join DEPENDENTE d
	on e.RG = d.RGRESPONSAVEL