void xen_barrier(void) {
	asm volatile ( "" : : : "memory");
}

#if defined(__i386__)
void xen_mb(void) {
	asm volatile ( "lock addl $0, -4(%%esp)" ::: "memory" );
}

void xen_rmb(void) {
	xen_barrier();
}

void xen_wmb(void) {
	xen_barrier();
}

#elif defined(__x86_64__)
void xen_mb(void) {
	asm volatile ( "lock addl $0, -32(%%rsp)" ::: "memory" );
}

void xen_rmb(void) {
	xen_barrier();
}

void xen_wmb(void) {
	xen_barrier();
}
#elif defined(__arm__)
void xen_mb(void) {
	asm volatile ("dmb" : : : "memory");
}

void xen_rmb(void) {
	asm volatile ("dmb" : : : "memory");
}

void xen_wmb(void) {
	asm volatile ("dmb" : : : "memory");
}
#elif defined(__aarch64__)
void xen_mb(void) {
	asm volatile ("dmb sy" : : : "memory");
}

void xen_rmb(void) {
	asm volatile ("dmb sy" : : : "memory");
}

void xen_wmb(void) {
	asm volatile ("dmb sy" : : : "memory");
}
#endif
