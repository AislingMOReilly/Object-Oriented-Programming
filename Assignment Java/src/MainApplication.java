//	Author: Aisling O'Reilly	Class: DCOM2-A

import java.util.ArrayList;
import java.util.Date;

public class MainApplication {

	public static void main(String[] args) {
		Date dt = new Date();
		
		ArrayList<Patient> patientList = new ArrayList<Patient> ();
	      
		Patient p1 = new Patient("John Doe", "Summerhill", 101);
		Patient p2 = new Patient("Jane Smith", "Douglas", 127);
		Patient p3 = new Patient("Mary Clark", "Sunday's Well", 132);
		
		Invoice i1 = new Invoice(7041, 150, dt, true);
		Invoice i2 = new Invoice(7117, 450, null, true);
		Invoice i3 = new Invoice(7101, 300, dt, true);
		Invoice i4 = new Invoice(7033, 75, null, false);
		
		Procedure pr1 = new Procedure(012, "Filling", 150);
		Procedure pr2 = new Procedure(102, "Teeth Whitening", 375);
		Procedure pr3 = new Procedure(007, "Root Canal", 300);
		Procedure pr4 = new Procedure(023, "Deep Cleaning", 75);
		
		Payment pay1 = new Payment(1, 150, null);
		Payment pay2 = new Payment(1, 450, dt);
		Payment pay3 = new Payment(1, 150, null);	
		Payment pay4 = new Payment(2, 150, dt);	
		
		i1.addProcedure(pr1);
		i2.addProcedure(pr4);
		i2.addProcedure(pr2);
		i3.addProcedure(pr3);
		i4.addProcedure(pr4);
		
		i1.addPayment(pay1);
		i2.addPayment(pay2);
		i3.addPayment(pay3);
		i3.addPayment(pay4);
		
		p1.addInvoice(i1);
		p1.addInvoice(i2);
		p2.addInvoice(i3);
		p3.addInvoice(i4);
		
		patientList.add(p1);
		patientList.add(p2);
		patientList.add(p3);	
		
		for(int i = 0; i< patientList.size(); i++){
			System.out.println(patientList.get(i) + "\n\n");
		}
		
	}

}
