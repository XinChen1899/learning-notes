package DAO.deptDAO;


import DAO.OperationDAO;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import module.DeptData;

public class DeptOperationDAOImpl implements OperationDAO<DeptData> {
    private static String sql;
    private static Connection conn;
    private static DeptOperationDAOImpl operation;
    private DeptOperationDAOImpl(Connection conn) {
        this.conn = conn;
    }
    public static DeptOperationDAOImpl getInstance(Connection conn) {
        if (operation == null)
            operation = new DeptOperationDAOImpl(conn);
        return operation;
    }
    public boolean insertData(DeptData data)
    {
        try {
            sql = "INSERT INTO Dept VALUES(?,?,?,?,?)";
            PreparedStatement pst = conn.prepareStatement(sql);
            pst.setString(1, data.getId());
            pst.setString(2, data.getName());
            pst.setString(3, data.getType());
            pst.setString(4, data.getDiscription());
            pst.setString(5, data.getAdress());
            int i = pst.executeUpdate();
            System.out.printf("插入数据成功，影响了%d行数据\n", i);
        } catch (SQLException e) {
            System.out.println("插入失败，或许该科室已存在，请检查科室编号");
            return false;
        }
        return true;
    }
    public boolean queryData()
    {
        ResultSet result;
        try {
            PreparedStatement pst=conn.prepareStatement(sql);
            result=pst.executeQuery();
            System.out.println("启动查询......");
            while(result.next())
            {
                System.out.println("id:"+result.getString(1)+' '+
                        "名称:"+result.getString(2)+' '+
                        "类型:"+result.getString(3)+' '+
                        "描述:"+result.getString(4)+' '+
                        "病区或地址:"+result.getString(5));
            }
        }
        catch(SQLException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }
    public boolean queryDataAll()
    {
        sql="SELECT * FROM Dept";
        return queryData();
    }
    public boolean readData(DeptData newDept)
    {
        ResultSet result;
        try {
            PreparedStatement pst=conn.prepareStatement(sql);
            result=pst.executeQuery();
            System.out.println("读取数据......");
            while(result.next())
            {
                newDept.setId(result.getString(1));
                newDept.setName(result.getString(2));
                newDept.setType(result.getString(3));
                newDept.setDiscription(result.getString(4));
                newDept.setAdress(result.getString(5));
            }
        }
        catch(SQLException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }
    public boolean deleteData(String id)
    {
        try {
            sql="DELETE FROM Dept WHERE id="+'\''+id+'\'';
            PreparedStatement pst=conn.prepareStatement(sql);
            int i=pst.executeUpdate();
            System.out.println("正在删除数据......");
            System.out.printf("删除成功，影响了%d行数据\n",i);
        }
        catch(SQLException e) {
            System.out.println("删除失败，或许不存在相应科室");
            return false;
        }
        return true;
    }
    public boolean findData(String id,DeptData dept)
    {
        sql="SELECT * FROM dept WHERE id=\'"+id+'\'';
        readData(dept);
        if(dept.getId()==null)
            return false;
        return true;
    }
}
