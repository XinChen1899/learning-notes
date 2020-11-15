import application.*;
import java.util.Scanner;
import java.sql.Connection;
import DAO.DataBaseConnection;


public class MainClass {
    public static void main(String args[])
    {
        int mainChoice=1;
        Scanner reader=new Scanner(System.in);
        Connection conn=DataBaseConnection.getConnection();
        while(mainChoice!=0)
        {
            System.out.println
                    ("**************欢迎使用609医院服务平台**************\n"
                            +"请选择:\n"
                            +"1、病人    2、医护    0、退出");
            try{
                mainChoice=reader.nextInt();
            }
            catch(Exception e){
                System.out.println("输入错误");
                break;
            }
            if(mainChoice==1)
                PatientRun.run(reader,conn);
            else if(mainChoice==2)
                DoctorRun.run(reader,conn);
            else if(mainChoice==0)
                break;
        }
    }
}
