package br.com.exception;

public class DataAccessException extends RuntimeException {
    // Construtor que recebe uma mensagem e uma causa (exceção original).
    public DataAccessException(String message, Throwable cause) {
        super(message, cause);
    }
}
