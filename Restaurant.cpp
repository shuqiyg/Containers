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
#include "Restaurant.h"

namespace sdds {
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
		if (reservations != nullptr) {
			noOfResv = cnt;
			resv = new Reservation[cnt];
			for (size_t i = 0; i < cnt; i++) {
				resv[i] = *reservations[i];
			}
		}
	}
	Restaurant::Restaurant(const Restaurant& rest) {
		*this = rest;
	}
	Restaurant& Restaurant::operator=(const Restaurant& rest) {
		if (this != &rest) {
			delete[] resv;
			noOfResv = rest.noOfResv;
			resv = new Reservation[noOfResv];
			for (size_t i = 0; i < noOfResv; i++) {
				resv[i] = rest.resv[i];
			}
		}
		return *this;
	}
	Restaurant::Restaurant(Restaurant&& rest) noexcept {
		*this = std::move(rest);
	}
	Restaurant& Restaurant::operator=(Restaurant&& rest) noexcept {
		if (this != &rest) {
			delete[] resv;
			resv = rest.resv;
			rest.resv = nullptr;
			noOfResv = rest.noOfResv;
			rest.noOfResv = 0u;
		}
		return *this;
	}
	Restaurant::~Restaurant() {
		delete[] resv;
	}
	size_t Restaurant::size() const {
		return noOfResv;
	}
	std::ostream& operator << (std::ostream& os, const Restaurant& rest) {
		static unsigned CALL_CNT = 0;
		os << "--------------------------\n" << "Fancy Restaurant (" << ++CALL_CNT << ")\n" << "--------------------------\n";
		if (rest.resv == nullptr) {
			os  << "This restaurant is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < rest.size(); i++) {
				os << rest.resv[i];
			}
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}
