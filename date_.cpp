namespace Chrono{
	enum class Month {jan =1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
	class Date{
		public://public interface
			class Bad_date{};//exception class
			explicit Date(int dd={}, Month mm = {}, int yy = {});// {} means "pick a default"									     
			//non-modifying functions for examining the Date:
			int day() const;
			Month month() const;
			int year() const;

			string string_rep() const;
			void char_rep(char s[], int max) const;

			//modifying functions for changing the Date;		
			Date& add_year(int n);
			Date& add_month(int n);
			Date& add_day(int n);
		private:
			bool is_valid(); //check if Date represents a date
			mutable cur_repr_cache;
			int d,m,y;       //representation
	};
	bool is_date(int d, Month m, int y); //true for valid date
	bool is_leapyear(int y); //true if y is leapyear
	
	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);

	const Date& default_date(); //default date

	ostream& operator<<(ostream& os, const Date& d); //print d to os
	istream& operator>>(istream& is, Date& d);    //read Date from is into d

}
