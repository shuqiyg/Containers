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
#ifndef RESERVATION_H_
#define RESERVATION_H_


namespace sdds {
	class Reservation {
		std::string resv_id {};
		std::string name {};
		std::string email {};
		unsigned noOfPpl {};
		unsigned day {}; // 1-28
		unsigned hour {};  // 1-24
	public:
		Reservation();
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream&, const Reservation&);
	};
}





#endif

