import java.util.ArrayList;

public class Patient extends Person {	
	private int PatientNo;
	
	//private Dentist dentist;
	
	private ArrayList<Invoice> p_invoiceList = new ArrayList<Invoice> ();
	
	public Patient(String n, String a) {super(n, a);}
	public Patient(String n, String a, int pn) {super(n, a); PatientNo = pn; }
	
	public int getPatientNo() {return PatientNo;};
	public void setPatientNo(int pn) {PatientNo = pn;};
	
	//Invoice methods
	public Invoice getInvoice(int i) {
		if (i>-1 && i <p_invoiceList.size())
			return p_invoiceList.get(i);
		return null;
	}
	public void addInvoice(Invoice i) {p_invoiceList.add(i);}
	
	public String toString() {
		String s = "\n\tPatient Details\n\t_______________\n\t_______________\n\n\tPatient Number: " + PatientNo + "\n\tName: " + getName() + "\n\tAddress: " + getAddress();
		
		s += "\n\n\t_________\n\tInvoices:\n\t_________\n" + p_invoiceList;
		return s;
	}
	public void print(Patient p) {
		System.out.println(p.toString());
	}
	
}
