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
#include "ConfirmationSender.h"

namespace sdds {
	ConfirmationSender::ConfirmationSender() {};
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& conSender) {
		*this = conSender;

	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& conSender) noexcept {
		*this = std::move(conSender);

	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& conSender) {
		if (this != &conSender) {
			delete[] reservations;
			noOfResvptr = conSender.noOfResvptr;
			reservations = new const Reservation * [noOfResvptr];
			for (size_t i = 0; i < noOfResvptr; i++) {
				reservations[i] = conSender.reservations[i];
			}
		}
		return *this;

	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& conSender) noexcept {
		if (this != &conSender) {
			delete[] reservations;
			reservations = conSender.reservations;
			conSender.reservations = nullptr;
			noOfResvptr = conSender.noOfResvptr;
			conSender.noOfResvptr = 0u;
		}
		return *this;

	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		if (reservations == nullptr) {
			reservations = new const sdds::Reservation*[++noOfResvptr];
			reservations[0] = &res;
		}else{
			bool exist = false;
			for (size_t i = 0; i < noOfResvptr && !exist; i++) {
				exist = (reservations[i] == &res ? true : false);
			}
			if (!exist) {
				const sdds::Reservation** resize = new const sdds::Reservation*[++noOfResvptr];
				for (size_t i = 0; i < noOfResvptr - 1; i++) {
					resize[i] = reservations[i];
				}
				resize[noOfResvptr -1] = &res;
				delete[] reservations;
				reservations = std::move(resize);			
			}
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		bool exist = false;
		size_t i;
		for (i = 0; i < noOfResvptr && !exist; i++) {
			exist = reservations[i] == &res ? true : false;
		}
		if (exist) {
			for (; i < noOfResvptr; i++) reservations[i - 1] = reservations[i];
			if (noOfResvptr) {
				reservations[noOfResvptr - 1] = nullptr;
				noOfResvptr--;
			}	
		}
		return *this;
	}
	ConfirmationSender::~ConfirmationSender() {
		delete[] reservations;
	}
	std::ostream& operator << (std::ostream& os, const ConfirmationSender& conSender) {
		os << "--------------------------\n" << "Confirmations to Send\n" << "--------------------------\n";
		if (conSender.reservations == nullptr) {
			os << "There are no confirmations to send!\n" << "--------------------------" << std::endl;
		}
		else {
			for (size_t i = 0; i < conSender.noOfResvptr; i++) {
				os << *(conSender.reservations[i]);
			}
			os << "--------------------------" << std::endl;
		}
		return os;
	}
}