package DAO.doctorDAO;

import DAO.OperationDAO;
import module.DoctorData;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class DoctorOperationDAOImpl implements OperationDAO<DoctorData> {
    private String sql;
    private static DoctorOperationDAOImpl operation;
    private Connection conn;
    private DoctorOperationDAOImpl(Connection conn)
    {
        this.conn=conn;
    }
    public static DoctorOperationDAOImpl getInstance(Connection conn)
    {
        if(operation==null)
            operation=new DoctorOperationDAOImpl(conn);
        return operation;
    }
    public boolean insertData(DoctorData data)
    {
        try {
            sql="INSERT INTO Doctor VALUES(?,?,?,?,?)";
            PreparedStatement pst=conn.prepareStatement(sql);
            pst.setString(1,data.getId());
            pst.setString(2,data.getName());
            pst.setString(3,data.getDept_id());
            pst.setString(4,data.getSex());
            pst.setString(5,data.getPassword());
            int i=pst.executeUpdate();
            System.out.printf("插入数据成功，影响了%d行数据\n",i);
        }
        catch(SQLException e) {
            System.out.println("插入失败，或许该id重合了");
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
                        "姓名:"+result.getString(2)+' '+
                        "部门编号:"+result.getString(3)+' '+
                        "性别:"+result.getInt(4));
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
        sql="SELECT * FROM Doctor";
        return queryData();
    }
    public boolean readData(DoctorData newDoctor)
    {
        ResultSet result;
        try {
            PreparedStatement pst=conn.prepareStatement(sql);
            result=pst.executeQuery();
            System.out.println("读取数据......");
            while(result.next())
            {
                newDoctor.setId(result.getString(1));
                newDoctor.setName(result.getString(2));
                newDoctor.setDept_id(result.getString(3));
                newDoctor.setSex(result.getString(4));
                newDoctor.setPassword(result.getString(5));
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
            sql="DELETE FROM Doctor WHERE id="+'\''+id+'\'';
            PreparedStatement pst=conn.prepareStatement(sql);
            int i=pst.executeUpdate();
            System.out.println("正在删除数据......");
            System.out.printf("删除成功，影响了%d行数据\n",i);
        }
        catch(SQLException e) {
            System.out.println("删除失败，或许不存在该医生");
            return false;
        }
        return true;
    }
    public boolean findData(String id,DoctorData doctor)
    {
        sql="SELECT * FROM Doctor WHERE id=\'"+id+'\'';
        readData(doctor);
        if(doctor.getId()==null)
            return false;
        return true;
    }
}
