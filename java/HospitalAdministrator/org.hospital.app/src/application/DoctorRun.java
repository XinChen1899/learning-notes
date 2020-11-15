package application;

import DAO.deptDAO.DeptOperationDAOImpl;
import DAO.doctorDAO.DoctorOperationDAOImpl;
import DAO.patientDAO.PatientOperationDAOImpl;
import DAO.regitrationDAO.RegOperationDAOImpl;
import module.DoctorData;
import java.sql.Connection;
import java.util.Date;
import java.util.Scanner;


class DoctorApp implements RegisterOperation<DoctorData> {
    private DoctorData doctor;
    private static DoctorApp instance;
    private static RegOperationDAOImpl regOperationDAO;
    private static DoctorOperationDAOImpl doctorOperationDAO;
    private Connection conn;
    private DoctorApp(Connection conn)
    {
        this.conn=conn;
    }
    public static DoctorApp getInstance(Connection conn)
    {
        if(instance==null)
        {
            instance=new DoctorApp(conn);
            doctorOperationDAO=DoctorOperationDAOImpl.getInstance(conn);
            regOperationDAO=RegOperationDAOImpl.getInstance(conn);
        }
        return instance;
    }
    public boolean signUp(DoctorData newDoctor)
    {
        doctor=newDoctor;
        return doctorOperationDAO.insertData(newDoctor);
    }
    public boolean logIn(String id,String password)
    {
        doctor=new DoctorData();
        if(doctorOperationDAO.findData(id,doctor))
            if(doctor.getPassword().equals(password))
                return true;
            else
                System.out.println("密码错误");
        return false;
    }
    public void showReg()
    {
        regOperationDAO.queryRegByDept(doctor.getDept_id());
    }
    public void showPatient() { PatientOperationDAOImpl.getInstance(conn).queryPatientByDept(doctor.getDept_id()); }
    public void showRegByDate(java.util.Date time)
    {
        regOperationDAO.queryRegByDate(time);
    }
    public boolean dealReg(String id)
    {
        System.out.println("挂号已被受理");
        return regOperationDAO.deleteData(id);
    }
    public void logOut()
    {
        doctorOperationDAO=null;
        regOperationDAO=null;
        instance=null;
    }
    public void cancelAccount()
    {
        doctorOperationDAO.deleteData(doctor.getId());
        logOut();
    }
}


public class DoctorRun{
    public static void run(Scanner reader,Connection conn)
    {
        byte userChoice=0;
        DoctorApp app=DoctorApp.getInstance(conn);
        System.out.println
                ("请选择:\n"
                        +"1、登录      2、注册      rest、退出");
        try {
            userChoice=reader.nextByte();
        }
        catch(Exception e){
            System.out.println("输入错误");
            return;
        }
        if(userChoice==1)
        {
            System.out.print("id: ");
            String id=reader.next();
            System.out.print("\n密码: ");
            String password=reader.next();
            if(!app.logIn(id,password))
            {
                System.out.println("登陆失败");
                return;
            }
        }
        else if(userChoice==2)
        {
            System.out.print("id: ");
            String id=reader.next();
            System.out.println(id);
            System.out.print("\n密码: ");
            String password=reader.next();
            System.out.print("\n姓名: ");
            String name=reader.next();
            System.out.print("\n性别: ");
            String sex=reader.next();
            System.out.print("\n年龄:");
            DeptOperationDAOImpl.getInstance(conn).queryDataAll();
            System.out.println("科室编号:");
            String deptId=reader.next();
            if(!app.signUp(new DoctorData(id,name,deptId,sex,password)))
            {
                System.out.println("注册失败");
                return;
            }
        }
        else
            return;
        while(true)
        {
            userChoice=0;
            System.out.println("请选择：1，处理挂号\n2，显示挂号记录\n3，查看所有病人\n" +
                    "4，查看指定日期挂号\n5，退出登录\n6，注销账号");
            while(userChoice==0)
            {
                try{
                    userChoice=reader.nextByte();
                }
                catch(Exception e) {
                    System.out.println("输入有误");
                    return;
                }
            }
            switch (userChoice)
            {
                case 1:
                    app.showReg();
                    System.out.println("请输入所要处理的挂号的病人id");
                    String patientId=reader.next();
                    app.dealReg(patientId);
                case 2:
                    app.showReg();
                    break;
                case 3:
                    app.showPatient();
                    break;
                case 4:
                    app.showRegByDate(new Date(System.currentTimeMillis()));
                    break;
                case 5:
                    app.logOut();
                    return;
                case 6:
                    System.out.println("您确定要注销账号吗？\n输入1确定");
                    userChoice=reader.nextByte();
                    if(userChoice==1)
                    {
                        app.cancelAccount();
                        return;
                    }
                    else
                        break;
                default:
                    break;
            }
        }
    }
}
