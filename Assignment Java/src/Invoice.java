import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Date;

public class Invoice {
	private int invNo;
	private double invAmount;
	private Date invDate;
	private boolean isPaid;
	DecimalFormat df = new DecimalFormat("#.##");
	
	private ArrayList<Procedure> in_procList = new ArrayList<Procedure> ();
	private ArrayList<Payment> in_paymentList = new ArrayList<Payment> ();

	public Invoice(Date d) {invDate = d;}
	public Invoice(int i, double ia, Date d, boolean p) {invNo = i; invAmount = ia; invDate = d; isPaid = p;}
	
	public int getInvNo() {return invNo;}
	public double getInvAmount() {return invAmount;}
	public Date getInvDate() {return invDate;}
	public boolean getPaid() {return isPaid;}
	
	public void setInvNo(int in) {invNo = in;}
	public void setInvAmount(double ia) {invAmount = ia;}
	public void setInvDate(Date d) {invDate = d;}
	public void setPaid(boolean p) {isPaid = p;}
	
	//Procedure methods
	public Procedure getProcedure(int i) {
		if (i>-1 && i <in_procList.size())
			return in_procList.get(i);
		return null;
	}
	public void addProcedure(Procedure p) {in_procList.add(p);}
	public void remProcedure(String name) {
		for(int i = 0; i<=in_procList.size(); i++){
			if (in_procList.get(i).equals(name))
				in_procList.remove(i);
		}
	}
	public void remProcedurebyIndex(int i) {
		if (i>-1 && i <in_procList.size())
			in_procList.remove(i);
	}
	public void setProcedure(int i, Procedure p) {
		if (i>-1 && i <in_procList.size())
			in_procList.set(i, p);
	}
	
	//Payment methods
	public Payment getPayment(int i) {
		if (i>-1 && i <in_procList.size())
			return in_paymentList.get(i);
		return null;
	}
	public void addPayment(Payment p) {in_paymentList.add(p);}
	
	
	public String toString() {
		String s = "\n\tInvoice Details\n\n\tInvoice Number: " + invNo + "\n\tDate: " + invDate + "\n\tAmount: " + df.format(invAmount) + "\n\tPaid: " + isPaid + "\n";
		
		s += "\n\n\tProcedures:\n\t___________\n" + in_procList;
		s += "\n\n\tPayments:\n\t_________\n" + in_paymentList;
		
		return s;
	}
	
	public void print(Invoice i) {
		System.out.println(i.toString());
	}

}
