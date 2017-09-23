import java.text.DecimalFormat;
import java.util.Date;

public class Payment {
	private int payNo;
	private double payAmount;
	private Date payDate;
	DecimalFormat df = new DecimalFormat("#.##");

	Payment(double a, Date d) {payAmount = a; payDate = d;}
	Payment(int pn, double a, Date d) {payNo = pn; payAmount = a; payDate = d;}
	public int getPayNo() {return payNo;}
	public double getPayAmount() {return payAmount;}
	public Date getPayDate() {return payDate;}
	
	public void setPayNo(int pn) {payNo = pn;}
	public void setPayAmount(double pa) {payAmount = pa;}
	public void setPayDate(Date d) {payDate = d;}
	
	public String toString() {
		String s = "\n\tPayment Details\n\n\tPayment Number: " + payNo + "\n\tAmount: " + df.format(payAmount) + "\n\tDate: " + payDate + "\n\n";
		return s;
	}
	
	public void print(Payment p) {
		System.out.println(p.toString());
	}
	
}
