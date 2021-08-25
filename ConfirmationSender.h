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
#ifndef CONFIRMATIONSENDER_H_
#define CONFIRMATIONSENDER_H_
#include <iostream>
#include <cstring>
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender {
		const sdds::Reservation** reservations = nullptr;
		size_t noOfResvptr = 0u;
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender(ConfirmationSender&&) noexcept;
		ConfirmationSender& operator=(const ConfirmationSender&);
		ConfirmationSender& operator=(ConfirmationSender&&) noexcept;
		ConfirmationSender& operator+=(const Reservation&);
		ConfirmationSender& operator-=(const Reservation&);
		~ConfirmationSender();
		friend std::ostream& operator << (std::ostream&, const ConfirmationSender&);

	};
}

#endif
