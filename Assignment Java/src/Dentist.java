//import java.util.ArrayList;

public class Dentist extends Person {
	private String Password;
	
	//private ArrayList<Patient> patientList = new ArrayList<Patient> ();
	
	public Dentist(String n, String a, String p) {super(n, a); Password = p;}
	
	public String getPassword() {return Password;};
	public void setPassword(String p) {Password = p;};
	
}
