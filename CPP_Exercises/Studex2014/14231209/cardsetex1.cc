//
//
// cardsetextra.cc - �g�����v�J�[�h�̏W���^(C++��)�e�X�g�v���O����
//	���: �����@�^�l; ���t: 2014/04/17
//
#include <iostream>
#include "cardset.h"

//
// main() - �g�����v�J�[�h�̏W���^�e�X�g�v���O����
//

int main (int argc, char * const argv[]) {
	

		Card c;
		CardSet cs;




		cs.print();
		// ���͂��G���[�ɂȂ�܂Ŏw�肵���J�[�h������
		std::cout << "insert: c = ? ";
		while(true) {
		  c.scan();
		  if (! c.isValid())
		    break;
		  if(cs.insert(c))
		    std::cout << "\tinsert error\n";
		  std::cout << "insert: c = ? ";
		}
		cs.print();//�I�������J�[�h��\��
		
		printf("\n");
		std::cout << "remove: c = ? ";
		while(true) {
		  c.scan();
		  if (! c.isValid())
		    break;
		  if(cs.remove(c))
		    std::cout << "\tremove error\n";
		  std::cout << "remove: c = ? ";
		}
		cs.print();
	return 0;
}
