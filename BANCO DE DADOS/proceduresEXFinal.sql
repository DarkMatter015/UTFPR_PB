use BANCOS

-- 1. Procedure para Transferência de Saldo entre Contas
create procedure SP_INS_Saldo_entre_Contas (
@ContaOrigem int, 
@ContaDestino int,
@valorTransferencia decimal(10,2)
)
AS
BEGIN

	DECLARE @SaldoOrigem DECIMAL(12,2);

	SELECT @SaldoOrigem = SALDO
    FROM CONTA
    WHERE NUMCONTA = @ContaOrigem;

if (@SaldoOrigem < @valorTransferencia) 
print('ERRO! Saldo insuficiente.')


	update CONTA
	set saldo = saldo + @valorTransferencia
	where nunconta = @numContaDestino