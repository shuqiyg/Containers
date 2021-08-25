/* Workshop 4 - Containers
   Name: Shuqi Yang
   Std ID: 132162207
   Email: syang136@myseneca.ca
   Date: 06-16-2021
   -------------------------------------------------------
   I have done all the coding by myself and only copied the
   code that my professor provided to complete my workshops
   and assignments.
 */
#include <string>
#include <iostream>
#include <iomanip>
#include "Reservation.h"

namespace sdds {
	Reservation::Reservation() {};
	Reservation::Reservation(const std::string& res) {
		//ID
		int colon_pos = res.find(":");
		resv_id = res.substr(0, colon_pos);
		int start = resv_id.find_first_not_of(' ');
		int end = resv_id.find_last_not_of(' ');
		resv_id = resv_id.substr(start, end - start + 1);
		/*resv_id.erase(std::find(resv_id.begin(), resv_id.end(), " "));
		resv_id.erase(resv_id.find(' '));*/
		//NAME
		int name_pos = colon_pos + 1;
		int first_comma = res.find(',', name_pos);
		name = res.substr(name_pos, first_comma - name_pos);
		start = name.find_first_not_of(' ');
		end = name.find_last_not_of(' ');
		name = name.substr(start, end - start + 1);
		//Email
		int email_pos = first_comma + 1;
		int second_comma = res.find(',', email_pos);
		email = res.substr(email_pos, second_comma - email_pos);
		start = email.find_first_not_of(' ');
		end = email.find_last_not_of(' ');
		email = email.substr(start, end - start + 1);
		//number of people
		int noOfPpl_pos = second_comma + 1;
		int third_comma = res.find(',', noOfPpl_pos);
		std::string noPpl_str = res.substr(noOfPpl_pos, third_comma);
		noOfPpl = stoi(noPpl_str);
		//day
		int day_pos = third_comma + 1;  
		int fourth_comma = res.find(',', day_pos);
		std::string day_str = res.substr(day_pos, fourth_comma);
		day = stoi(day_str);
		//hour
		int hour_pos = fourth_comma + 1;
		std::string hour_str = res.substr(hour_pos);
		hour = stoi(hour_str);
	}
	std::ostream& operator << (std::ostream& os, const Reservation& res) {
		os << "Reservation " << std::setw(10) << std::right << res.resv_id << ": ";
		os << std::setw(20) << std::right << res.name  << std::setw(25) << std::left << "  <" + res.email + ">" <<  std::left;
		if (res.hour >= 6 && res.hour <= 9) {
			os << " Breakfast on day ";
		}
		else if (res.hour >= 11 && res.hour <= 15) {
			os << " Lunch on day ";
		}
		else if (res.hour >= 17 && res.hour <= 21) {
			os << " Dinner on day ";
		}
		else {
			os << " Drinks on day ";
		}
		os << res.day << " @ " << res.hour << ":00 for " << res.noOfPpl;
		os << (res.noOfPpl == 1 ? " person." : " people.") << std::endl;
		return os;
	}
	
}