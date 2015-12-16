/**
* Developer: Minhas Kamal(BSSE0509, IIT, DU)
* Date: 09-Feb-2015
**/

package balanceTree;

public class Touple {
	public int[] values;
	
	public Touple() {
		values = new int[3];
		for(int i=0; i<3; i++){
			values[i] = 0;
		}
	}
	
	public Touple(int[] values) {
		this.values = values;
	}
	
	public Touple(String[] values) {
		this.values = new int[values.length];
		
		for(int i=0; i<values.length; i++){
			this.values[i] = Integer.parseInt(values[i]);
		}
	}
	
	public String dupm() {
		String str = "(" + values[0];
		
		for(int i=1; i<values.length; i++){
			str += "," + values[i];
		}
		
		str += ")";
		return str;
	}
	
	public static void main(String[] args) {
		String[] values = {"10", "3", "11"};
		
		Touple touple = new Touple(values);
		
		System.out.println(touple.dupm());
	}
}
