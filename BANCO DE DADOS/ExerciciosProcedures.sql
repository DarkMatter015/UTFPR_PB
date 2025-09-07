-- 1) Crie uma function que receba como par�metro uma data de nascimento e retorne a idade desta pessoa atualmente. Use fun��es de manipula��o de data para isso.

create or alter function CALCULAR_IDADE(@AnoNascimento int)
returns int
as
begin
declare @idade int;
set @idade = year(GETDATE()) - @AnoNascimento;
return @idade;
end

begin
declare
@idade int
exec @idade = CALCULAR_IDADE @AnoNascimento = 2006
print 'A idade � ' + (cast(@idade as char(3))) + 'anos'
end


-- 2) Crie uma function que receba como par�metro um nome de uma pessoa e coloque este nome com letras mai�scula e imprima o mesmo.
create or alter function NOME_MAIUSCULA(@Nome varchar)
returns varchar
as
begin
set @Nome
return @Nome
end

begin
declare
@Nome varchar
exec @Nome = NOME_MAIUSCULA @Nome = 'lucas'
print @Nome
end