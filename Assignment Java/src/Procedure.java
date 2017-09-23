import java.text.DecimalFormat;

public class Procedure {
	private int procNo;
	private String procName;
	private double procCost;
	DecimalFormat df = new DecimalFormat("#.##");
	
	Procedure(String pn, double pc) {procName = pn; procCost = pc;}
	Procedure(int p, String pn, double pc) {procNo = p; procName = pn; procCost = pc;}
	public int getProcNo() {return procNo;}
	public String getProcName() {return procName;}
	public double getProcCost() {return procCost;}
	
	public void setProcNo(int pn) {procNo = pn;}
	public void setProcName(String pn) {procName = pn;}
	public void setProcCost(double pc) {procCost = pc;}
	
	public String toString() {
		String s = "\n\tProcedure Details\n\n\tProcedure Number: " + procNo + "\n\tName: " + procName + "\n\tCost: " + df.format(procCost) + "\n\n";
		return s;
	}
	
	public void print(Procedure p) {
		System.out.println(p.toString());
	}
	
}
