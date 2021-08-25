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
#ifndef RESTAURANT_H_
#define RESTAURANT_H_
#include <iostream>
#include "Reservation.h"

namespace sdds {
	class Restaurant {
		Reservation* resv = nullptr;
		size_t noOfResv {};
	public:
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant&);
		Restaurant& operator=(const Restaurant&);
		Restaurant(Restaurant&&) noexcept;
		Restaurant& operator=(Restaurant&&) noexcept;
		~Restaurant();
		size_t size() const;
		friend std::ostream& operator << (std::ostream&, const Restaurant&);
	};
}


#endif
