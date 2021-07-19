#ifndef FGG_EXPORT_H
#define FGG_EXPORT_H


#define FGG_DEFINE_EXPORT_OFFSET(x, n) const uint32_t fgg ## x ## ExportOffset = n

#define FGG_DEFINE_EXPORT_SIZE(x, n) const uint32_t fgg ## x ## ExportSize = n  



extern void fggExport(const char* path);


#endif