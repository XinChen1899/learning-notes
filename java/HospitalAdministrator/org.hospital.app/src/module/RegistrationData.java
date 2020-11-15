package module;

import java.text.SimpleDateFormat;
import java.util.Date;

public class RegistrationData {
    private String id,patientId,deptId;
    private Date regTime;
    private int price;
    public RegistrationData()
    {
        id=null;patientId=null;deptId=null;regTime=new Date();price=0;
    }
    public RegistrationData(String patientId,String deptId,Date regTime,int price)
    {
        SimpleDateFormat formater=new SimpleDateFormat();
        formater.applyPattern("yyyyMMdd");
        String time=formater.format(regTime);
        this.id=patientId+deptId+time;
        this.patientId=patientId;
        this.deptId=deptId;
        this.regTime=regTime;
        this.price=price;
    }
    public String getId() {
        return id;
    }
    public String getPatientId() {
        return patientId;
    }
    public String getDeptId() {
        return deptId;
    }
    public Date getRegTime() {
        return regTime;
    }
    public int getPrice() {
        return price;
    }
    public void setId(String id) {
        this.id = id;
    }
    public void setPatientId(String patientId) {
        this.patientId = patientId;
    }
    public void setDeptId(String deptId) {
        this.deptId = deptId;
    }
    public void setRegTime(Date regTime) {
        this.regTime = regTime;
    }
    public void setPrice(int price) {
        this.price = price;
    }
    @Override
    public String toString() {
        return "id:"+getId()+" 病人编号:"+getPatientId()+
                " 部门编号:"+getDeptId()+" 挂号时间:"+getRegTime()+" 费用:"+getPrice();
    }
}
