package DAO.regitrationDAO;

import DAO.OperationDAO;
import module.RegistrationData;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Date;

public class RegOperationDAOImpl implements OperationDAO<RegistrationData> {
    private String sql;
    private static RegOperationDAOImpl operation;
    private Connection conn;
    private RegOperationDAOImpl(Connection conn)
    {
        this.conn=conn;
    }
    public static RegOperationDAOImpl getInstance(Connection conn)
    {
        if(operation==null)
            operation=new RegOperationDAOImpl(conn);
        return operation;
    }
    public boolean insertData(RegistrationData data)
    {
        try {
            sql="INSERT INTO reg_record VALUES(?,?,?,?,?)";
            PreparedStatement pst=conn.prepareStatement(sql);
            pst.setString(1,data.getId());
            pst.setString(2,data.getPatientId());
            pst.setString(3,data.getDeptId());
            pst.setDate(4,new Date(data.getRegTime().getTime()) );
            pst.setInt(5,data.getPrice());
            int i=pst.executeUpdate();
            System.out.printf("插入数据成功，影响了%d行数据\n",i);
        }
        catch(SQLException e) {
            System.out.println("插入失败，或许此挂号记录已存在");
            e.printStackTrace();
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
                        "病人:"+result.getString(2)+' '+
                        "部门:"+result.getString(3)+' '+
                        "挂号日期:"+new java.util.Date(result.getDate(4).getTime())+' '+
                        "费用:"+result.getInt(5));
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
        sql="SELECT reg_record.id,patient.name,dept.name,reg_time,price "+
            "FROM reg_record JOIN patient ON patient_id=patient.id JOIN dept ON dept_id=dept.id "+;
        return queryData();
    }
    public boolean queryRegByDate(java.util.Date time)
    {
        sql="SELECT reg_record.id,patient.name,dept.name,reg_time,price "+
            "FROM reg_record JOIN patient ON patient_id=patient.id JOIN dept ON dept_id=dept.id "+
            "WHERE reg_time=\'"+new java.sql.Date(time.getTime())+'\'';
        return queryData();
    }
    public boolean queryRegByPatient(String patientId)
    {
        sql="SELECT reg_record.id,patient.name,dept.name,reg_time,price "+
            "FROM reg_record JOIN patient ON patient_id=patient.id JOIN dept ON dept_id=dept.id "+
            "WHERE Patient_id="+'\''+patientId+'\'';
        return queryData();
    }
    public boolean queryRegByDept(String deptId)
    {
        sql="SELECT reg_record.id,patient.name,dept.name,reg_time,price "+
            "FROM reg_record JOIN patient ON patient_id=patient.id JOIN dept ON dept_id=dept.id "+
            "WHERE dept_id="+'\''+deptId+'\'';
        return queryData();
    }
    public boolean readData(RegistrationData newReg)
    {
        ResultSet result;
        try {
            PreparedStatement pst=conn.prepareStatement(sql);
            result=pst.executeQuery();
            System.out.println("读取数据......");
            while(result.next())
            {
                newReg.setId(result.getString(1));
                newReg.setPatientId(result.getString(2));
                newReg.setDeptId(result.getString(3));
                newReg.setRegTime(new java.util.Date(result.getDate(4).getTime()));
                newReg.setPrice(result.getInt(5));
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
            sql="DELETE FROM reg_record WHERE patient_id="+'\''+id+'\'';
            PreparedStatement pst=conn.prepareStatement(sql);
            int i=pst.executeUpdate();
            System.out.println("正在删除数据......");
            System.out.printf("删除成功，影响了%d行数据\n",i);
        }
        catch(SQLException e) {
            System.out.println("删除失败");
            return false;
        }
        return true;
    }
    public boolean findData(String id,RegistrationData registration)
    {
        sql="SELECT * FROM reg_record WHERE id=\'"+id+'\'';
        readData(registration);
        if(registration.getId()==null)
            return false;
        return true;
    }
}
