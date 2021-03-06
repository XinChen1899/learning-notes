package module;

public class PatientData {
    private String id,name,sex,password;
    private int age;
    public PatientData()
    {
        id=null;name=null;password=null;sex=null;age=0;
    }
    public PatientData(String id,String name,String password,int age,String sex)
    {
        this.id=id;
        this.name=name;
        this.password=password;
        this.age=age;
        this.sex=sex;
    }
    public String getId() {
        return id;
    }
    public String getName() {
        return name;
    }
    public String getSex() {
        return sex;
    }
    public int getAge() {
        return age;
    }
    public String getPassword() {
        return password;
    }
    public void setId(String id) {
        this.id = id;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setSex(String sex) {
        this.sex = sex;
    }
    public void setAge(int age) {
        this.age = age;
    }
    public void setPassword(String password) {
        this.password = password;
    }
    @Override
    public String toString()
    {
        return "id"+getId()+" 姓名:"+getName()+" 性别:"+getSex()+" 年龄:"+getAge();
    }
}
