#include "Brain.hpp"

Brain::Brain() {
	std::cout << "[Brain] default constructed" << std::endl;
}
Brain::Brain(const Brain &o) {
	for (int i=0;i<100;i++) ideas[i]=o.ideas[i];
	std::cout << "[Brain] copy constructed" << std::endl;
}
Brain &Brain::operator=(const Brain &o) {
	if (this!=&o){
		for(int i=0;i<100;i++) ideas[i]=o.ideas[i];
	}
	return *this;
}
Brain::~Brain() {
	std::cout << "[Brain] destroyed" << std::endl;
}
void Brain::setIdea(int i, const std::string &idea) {
	if (i>=0 && i<100) ideas[i]=idea;
}
std::string Brain::getIdea(int i) const {
	if (i>=0 && i<100) return ideas[i];
	return "";
}