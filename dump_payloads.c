#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#include "payloads.h"

void dump(const char *name, const uint8_t *buf, uint32_t len) {
	FILE *fp = fopen(name, "w+b");
	assert(fp);
	size_t nwritten = fwrite(buf, len, 1, fp);
	assert(nwritten == 1);
	int ret = fclose(fp);
	assert(ret == 0);
	return;
}

int main(void) {
	dump("plaintext_version.bin", plaintxt_version, plaintxt_version_len);
	dump("plaintext_miniloader.bin", plaintxt_miniloader, plaintxt_miniloader_len);
	dump("sbkv1_version.bin", sbkv1_version, sbkv1_version_len);
	dump("sbkv1_miniloader.bin", sbkv1_miniloader, sbkv1_miniloader_len);
	dump("sbkv2_version.bin", sbkv2_version, sbkv2_version_len);
	dump("sbkv2_miniloader.bin", sbkv2_miniloader, sbkv2_miniloader_len);
	return 0;
}
