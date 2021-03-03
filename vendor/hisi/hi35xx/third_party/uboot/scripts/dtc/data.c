#include "dtc.h"
void data_free(struct data d)
{
	struct marker *m, *nm;

	m = d.markers;
	while (m) {
		nm = m->next;
		free(m->ref);
		free(m);
		m = nm;
	}

	if (d.val)
		free(d.val);
}
