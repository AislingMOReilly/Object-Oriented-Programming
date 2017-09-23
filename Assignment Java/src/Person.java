
public class Person {
	
	private String Name;
	private String Address;
	
	Person(String n, String a) {setName(n); Address = a;}

	public String getName() {return Name;}
	public void setName(String nm) {Name = nm;}
	
	public String getAddress() {return Address;}
	public void setAddress(String ad) {Address = ad;}
}
