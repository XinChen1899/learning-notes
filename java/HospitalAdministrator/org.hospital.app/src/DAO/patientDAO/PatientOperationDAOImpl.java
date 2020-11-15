package DAO.patientDAO;

import DAO.OperationDAO;
import module.PatientData;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class PatientOperationDAOImpl implements OperationDAO<PatientData> {
    private String sql;
    private Connection conn;
    private static PatientOperationDAOImpl operation;
    private PatientOperationDAOImpl(Connection conn)
    {
        this.conn=conn;
    }
    public static PatientOperationDAOImpl getInstance(Connection conn)
    {
        if(operation==null)
            operation=new PatientOperationDAOImpl(conn);
        return operation;
    }
    public boolean insertData(PatientData data)
    {
        try {
            sql="INSERT INTO Patient VALUES(?,?,?,?,?)";
            PreparedStatement pst=conn.prepareStatement(sql);
            pst.setString(1,data.getId());
            pst.setString(2,data.getName());
            pst.setObject(3,data.getSex());
            pst.setInt(4,data.getAge());
            pst.setString(5,data.getPassword());
            int i=pst.executeUpdate();
            System.out.printf("插入数据成功，影响了%d行数据\n",i);
        }
        catch(SQLException e) {
            System.out.println("插入失败，或许id重合了");
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
                        "性别:"+result.getString(3)+' '+
                        "年龄:"+result.getInt(4));
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
        sql="SELECT * FROM Patient";
        return queryData();
    }
    public boolean queryPatientByDept(String deptId)
    {
        sql="SELECT id,name,sex,age FROM Patient WHERE id IN" +
                "(SELECT patient_id FROM reg_record WHERE dept_id=\'"+deptId+"\')";
        return queryData();
    }
    public boolean readData(PatientData newPatient)
    {
        ResultSet result;
        try {
            PreparedStatement pst=conn.prepareStatement(sql);
            result=pst.executeQuery();
            System.out.println("读取数据......");
            while(result.next())
            {
                newPatient.setId(result.getString(1));
                newPatient.setName(result.getString(2));
                newPatient.setPassword(result.getString(5));
                newPatient.setAge(result.getInt(4));
                newPatient.setSex(result.getString(3));
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
            sql="DELETE FROM Patient WHERE name="+'\''+id+'\'';
            PreparedStatement pst=conn.prepareStatement(sql);
            int i=pst.executeUpdate();
            System.out.println("正在删除数据......");
            System.out.printf("删除成功，影响了%d行数据\n",i);
        }
        catch(SQLException e) {
            System.out.println("删除失败，或许不存在该病人");
            return false;
        }
        return true;
    }
    public boolean findData(String id,PatientData patient)
    {
        sql="SELECT * FROM patient where id=\'"+id+'\'';
        readData(patient);
        if(patient.getId()==null)
            return false;
        return true;
    }
}
