package DAO;

import java.sql.Connection;
import java.sql.DriverManager;

public class DataBaseConnection {
    private static final String driverName="com.mysql.jdbc.Driver";
    private static final String url="jdbc:mysql://127.0.0.1:3306/hospital?useSSL=false";
    private static final String user="root";
    private static final String password="******";
    public static Connection getConnection()
    {
        Connection conn=null;
        try{
            Class.forName(driverName);
            conn= DriverManager.getConnection(url,user,password);
            System.out.println("MySql连接成功");
        }
        catch(Exception e)
        {
            e.printStackTrace();
            System.out.println("数据库连接失败");
        }
        return conn;
    }
}
