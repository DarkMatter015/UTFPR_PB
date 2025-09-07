-- 1) Cria as views abaixo para atender as seguintes necessidades de relatórios:

--a) Crie uma view para Listar o Nome de todas as Representada e a somatória de todas as vendas (VEN_VL_TOTAL) efetuadas para a representada.

create or alter view v_vendas_representadas
as
	select r.REP_NM as nome_representada, sum(v.VEN_VL_TOTAL) as total_vendas
	from REPRESENTADA r
	inner join VENDA v
	on r.REP_ID = v.REP_ID
group by r.REP_NM

select nome_representada, total_vendas
from v_vendas_representadas

--b) Crie uma view para listar todas as vendas (Nome do Cliente, Data da venda e Valor total da venda) e quantidade de parcelas que cada venda possui.

create or alter view v_qtd_parcelas_por_vendas
as
	select v.VEN_ID
	from VENDA v