#ifndef IDT_H
#define IDT_H
#include <SmartOS.h>
#ifdef __cplusplus
struct __attribute__((packed)) IDTEntry
{
    uint16_t offset0;
    uint16_t selector;
    uint8_t ist: 3;
    uint8_t rsv0: 5;
    uint8_t type: 5;
    uint8_t dpl: 2;
    uint8_t p: 1;
    uint16_t offset1;
    uint32_t offset2;
    uint32_t rsv1;
    IDTEntry();
    IDTEntry(uint64_t offset, uint16_t selector, uint8_t type, uint8_t dpl, uint8_t ist);
};
class IDT
{
private:
    IDTEntry entries[256];
public:
    IDT();
    void load();
};
void initializeIDT();
#endif
#endif