package module;

public class DeptData {
    protected String id,name,type,discription,adress;
    public DeptData()
    {
        id=null;
        name=null;
        type=null;
        discription=null;
        adress=null;
    }
    public DeptData(String id,String name,String type,String discription,String adress)
    {
        this.id=id;
        this.name=name;
        this.type=type;
        this.discription=discription;
        this.adress=adress;
    }
    public void setId(String newId) { id=newId; }
    public void setName(String newName)
    {
        name=newName;
    }
    public void setType(String type)
    {
        this.type=type;
    }
    public void setDiscription(String newDiscription)
    {
        discription=newDiscription;
    }
    public void setAdress(String adress) {
        this.adress = adress;
    }
    public String getId()
    {
        return id;
    }
    public String getName()
    {
        return name;
    }
    public String getType()
    {
        return type;
    }
    public String getDiscription()
    {
        return discription;
    }
    public String getAdress() {
        return adress;
    }
}
