#include "ribosome.h"
#include "nucleobase.h"
#include "nucleotide.h"
#include "codon.h"
#include "lib/list.h"

int main (int argc, char *argv[]){

  Ribosome r1 = new (Ribosome, ribosome);
  r1->setId(r1, 1);

  Ribosome r2 = new (Ribosome, ribosome);
  r2->setId(r2, 2);

  delete(r1);
  delete(r2);

  Nucleobase nb1 = new (Nucleobase, nucleobase);
  nb1->setType(nb1, GUANINE);
  Nucleotide ntd1 = new (Nucleotide, nucleotide);
  ntd1->setId(ntd1,1);
  ntd1->setNucleobase(ntd1, nb1);

  Nucleobase nb2 = new (Nucleobase, nucleobase);
  nb2->setType(nb2, CYTOSINE);
  Nucleotide ntd2 = new (Nucleotide, nucleotide);
  ntd2->setId(ntd2,1);
  ntd2->setNucleobase(ntd2, nb2);

  Nucleobase nb3 = new (Nucleobase, nucleobase);
  nb3->setType(nb3, ADENINE);
  Nucleotide ntd3 = new (Nucleotide, nucleotide);
  ntd3->setId(ntd3,1);
  ntd3->setNucleobase(ntd3, nb3);

  Codon c = new (Codon, codon);
  c->setId(c, 1);
  c->setNucleotide(c, ntd1, 0);
  c->setNucleotide(c, ntd2, 1);
  c->setNucleotide(c, ntd3, 2);

  delete(c);

  Item item = (Item) malloc(sizeof(item));
  int *value = (int *) malloc (sizeof(int));
  *value = 1;
  item->data = value;

  Item item2 = (Item) malloc(sizeof(item));
  value = (int *) malloc (sizeof(int));
  *value = 2;
  item2->data = value;

  List l1 = new (List, list);
  l1->add(l1, item);
  l1->add(l1, item2);

  Item testItem = l1->getIndex(l1, 2);
  printf("testItem data %d\n", *(int *)testItem->data);

  printf("l1 len %d\n",l1->getLen(l1));
  l1->empty(l1);
  printf("l1 len after empty %d\n",l1->getLen(l1));

  delete(l1);

  return 0;
}
