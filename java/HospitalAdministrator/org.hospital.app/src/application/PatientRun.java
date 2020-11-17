package application;

import DAO.deptDAO.DeptOperationDAOImpl;
import DAO.patientDAO.PatientOperationDAOImpl;
import DAO.regitrationDAO.RegOperationDAOImpl;
import module.DeptData;
import module.PatientData;
import module.RegistrationData;
import java.sql.Connection;
import java.util.Date;
import java.util.Scanner;

class PatientApp implements RegisterOperation<PatientData> {
    private PatientData patient;
    private static PatientApp instance;
    private static PatientOperationDAOImpl patientOperationDAO;
    private static RegOperationDAOImpl regOperationDAO;
    private Connection conn;
    private PatientApp(Connection conn)
    {
        this.conn=conn;
    }
    public static PatientApp getInstance(Connection conn)
    {
        if(instance==null)
        {
            instance=new PatientApp(conn);
            patientOperationDAO=PatientOperationDAOImpl.getInstance(conn);
            regOperationDAO=RegOperationDAOImpl.getInstance(conn);
        }
        return instance;
    }
    public boolean signUp(PatientData newPatient)
    {
        patient=newPatient;
        return patientOperationDAO.insertData(newPatient);
    }
    public boolean logIn(String id,String password)
    {
        patient=new PatientData();
        if(patientOperationDAO.findData(id,patient))
            if(password.equals(patient.getPassword()))
                return true;
            else
                System.out.println("密码错误");
        return false;
    }
    public boolean newRegistration(String deptId,String date)
    {
        java.text.SimpleDateFormat formatter=new SimpleDateFormat("yyyy-MM-dd");
        Date regTime;
        try{
            regTime=formatter.parse(date);
        }
        catch(java.text.ParseException e){
            e.getErrorOffset();
            return false;
        }
        RegistrationData newReg=new RegistrationData(patient.getId(),deptId,regTime,20);
        return regOperationDAO.insertData(newReg);
    }
    public void showReg()
    {
        regOperationDAO.queryRegByPatient(patient.getId());
    }
    public void logOut()
    {
        patientOperationDAO=null;
        regOperationDAO=null;
        instance=null;
    }
    public void cancelAccount()
    {
        patientOperationDAO.deleteData(patient.getId());
        logOut();
    }
}


public class PatientRun {
    public static void run(Scanner reader,Connection conn)
    {
        byte userChoice=0;
        PatientApp app=PatientApp.getInstance(conn);
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
            int age=-1;
            while(age==-1)
            {
                try{
                    age=reader.nextInt();
                }
                catch(Exception e) {
                    System.out.println("输入有误");
                }
            }
            if(!app.signUp(new PatientData(id,name,password,age,sex)))
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
            System.out.println("请选择：\n1，挂号\n2，查看挂号信息\n3，退出登录\n4，注销账号");
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
                    DeptOperationDAOImpl.getInstance(conn).queryDataAll();
                    System.out.println("请输入挂号科室编号:");
                    String deptId=reader.next();
                    System.out.println("日期：\n年：");
                    String year=reader.next();
                    System.out.println("月：");
                    String month=reader.next();
                    System.out.println("日：");
                    String day=raeder.next();
                    if(DeptOperationDAOImpl.getInstance(conn).findData(deptId,new DeptData()))
                        if(app.newRegistration(deptId,year+'-'+month+'-'+day))
                            System.out.println("挂号成功");
                        else
                            System.out.println("抱歉，挂号失败");
                    else
                        System.out.println("科室名称有误,挂号失败");
                    break;
                case 2:
                    app.showReg();
                    break;
                case 3:
                    app.logOut();
                    return;
                case 4:
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
