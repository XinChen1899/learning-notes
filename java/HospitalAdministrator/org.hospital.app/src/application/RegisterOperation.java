package application;

public interface RegisterOperation<E> {
    boolean signUp(E newObject);
    boolean logIn(String id,String password);
    void showReg();
    void logOut();
    void cancelAccount();
}
