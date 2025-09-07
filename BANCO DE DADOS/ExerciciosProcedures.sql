-- 1) Crie uma function que receba como parâmetro uma data de nascimento e retorne a idade desta pessoa atualmente. Use funções de manipulação de data para isso.

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
print 'A idade é ' + (cast(@idade as char(3))) + 'anos'
end


-- 2) Crie uma function que receba como parâmetro um nome de uma pessoa e coloque este nome com letras maiúscula e imprima o mesmo.
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