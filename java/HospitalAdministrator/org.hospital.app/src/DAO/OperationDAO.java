package DAO;


public interface OperationDAO<E> {
    public boolean insertData(E data);
    public boolean queryData();
    public boolean deleteData(String id);
    public boolean readData(E newE);
    public boolean findData(String id,E data);
}
