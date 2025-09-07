-- a)
use CONTROLE_PROJETOS
create or alter view V_Tarefas_dia_17
as
	select 
		t.DESCRICAOTAREFA,
		p.NOMEPROJETO,
		tt.NOMETIPOTAREFA,
		c.NOMECOLABORADOR,
		tcf.IDSTATUSTAREFA,
		t2.DESCRICAOTAREFA descricao_tarefa_dependente
	from TAREFA_COLABORADOR_FUNCAO tcf
	inner join TAREFA t on tcf.IDTAREFA = t.IDTAREFA
	inner join PROJETO p on t.IDPROJETO = p.IDPROJETO
	inner join TIPOTAREFA tt on t.IDTIPOTAREFA = tt.IDTIPOTAREFA
	inner join COLABORADOR c on tcf.IDCOLABORADOR = c.IDCOLABORADOR
	left join TAREFA t2 on t.IDTAREFADEPENDENTE = t2.IDTAREFA

	where 
		tcf.IDSTATUSTAREFA = 3
		AND tcf.DATAINICIOTAREFA >= CONVERT(DATETIME, '2025-17-06 08:00:00') AND tcf.DATAINICIOTAREFA <= CONVERT(DATETIME, '2025-17-06 10:00:00')
		AND tcf.DATATERMINOTAREFAREALIZADA <= CONVERT(DATETIME, '2025-17-06 18:00:00')

select DESCRICAOTAREFA,
		NOMEPROJETO,
		NOMETIPOTAREFA,
		NOMECOLABORADOR,
		IDSTATUSTAREFA,
		descricao_tarefa_dependente
from V_Tarefas_dia_17

-- b)

create or alter function F_Projeto_Funcao (@FUNCAO VARCHAR(250), @DATA varchar)
returns varchar(250)
as
BEGIN
	DECLARE @NOMES VARCHAR(250) = 'hcdbcwbu'

	return @NOMES

END

BEGIN
DECLARE @NOMES VARCHAR(250)
exec @NOMES = F_Projeto_Funcao ' ', ' '
print @NOMES
END



-- c)
create or alter procedure SP_PROJETO
(
	@PROJETO varchar(255)
)
as
	declare @qtd int = (
	select count(p.NOMEPROJETO) 
		from PROJETO p
		where
			p.IDSTATUSPROJETO != 2
	)
	if not exists (
		select p.IDPROJETO 
		from PROJETO p
		where
			p.IDSTATUSPROJETO = 2
			AND p.NOMEPROJETO = @PROJETO
		)
	begin 
	declare @cont int = @qtd
		while(@cont >= 0)
		begin
			
			
		end
		return;
	end

	print 'nao'

exec SP_PROJETO 'Projeto 1'

select * from PROJETO


-- d) 
create or alter trigger TG_TAREFA_COLABORADOR_FUNCAO
ON TAREFA_COLABORADOR_FUNCAO
FOR INSERT, UPDATE
AS
BEGIN
	declare @NomeTarefa varchar(250) = (select tcf.DATAINICIOTAREFA from TAREFA_COLABORADOR_FUNCAO tcf
			inner join inserted i on i.IDCOLABORADOR = tcf.IDCOLABORADOR
			where tcf.DATATERMINOTAREFAREALIZADA is null and tcf.DATAINICIOTAREFA <= i.DATAINICIOTAREFA)
		IF EXISTS (
			select tcf.DATAINICIOTAREFA from TAREFA_COLABORADOR_FUNCAO tcf
			inner join inserted i on i.IDCOLABORADOR = tcf.IDCOLABORADOR
			where tcf.DATATERMINOTAREFAREALIZADA is null and tcf.DATAINICIOTAREFA <= i.DATAINICIOTAREFA
			)
		begin
			update TAREFA_COLABORADOR_FUNCAO
				set 
				IDSTATUSTAREFA = 3,
				DATATERMINOTAREFAREALIZADA = GETDATE()
			where IDTAREFA = (select tcf.IDTAREFA from TAREFA_COLABORADOR_FUNCAO tcf
			inner join inserted i on i.IDCOLABORADOR = tcf.IDCOLABORADOR
			where tcf.DATATERMINOTAREFAREALIZADA is null and tcf.DATAINICIOTAREFA <= i.DATAINICIOTAREFA)

			print 'tarefa concluida: ' + @NomeTarefa
		end
		
	print 'operacao concluida: '
END

UPDATE TAREFA_COLABORADOR_FUNCAO
	set OBSERVACAO = 'Observacao teste'
where IDSTATUSTAREFA = 5

select * from TAREFA_COLABORADOR_FUNCAO
select * from STATUSTAREFA

--INTO TAREFA_COLABORADOR_FUNCAO (IDTAREFA, IDCOLABORADOR, IDFUNCAO, DATAINICIOTAREFA, DATATERMINOTAREFAPREVISTA, DATATERMINOTAREFAREALIZADA, IDSTATUSTAREFA, OBSERVACAO) 
--VALUES (5, 2, 2, '2025-02-05 08:50:00', '2025-18-07 18:00:00', '2025-18-08 13:03:43', 5, 'Sem observa��es');