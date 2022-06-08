#include "allocator.h"

LinearAllocator::LinearAllocator(u64 size, void* start) : Allocator(size, start), m_currentPosition(start) 
{
    OGLR_ASSERT(size > 0);
}

LinearAllocator::~LinearAllocator()
{
    m_currentPosition = nullptr;
}

void* LinearAllocator::allocate(u64 size, u64 alignment)
{
    OGLR_ASSERT(size != 0);

    u8 adjustment = alignment - (reinterpret_cast<uintptr_t>(m_currentPosition) & static_cast<uintptr_t>(alignment - 1));

    if (adjustment == alignment) adjustment = 0;

    if (m_memoryUsed + adjustment + size > m_totalSize) return nullptr;

    uintptr_t alignedAddress = (uintptr_t)m_currentPosition + adjustment;

    m_currentPosition = (void*)(alignedAddress + size);
    m_memoryUsed += size + adjustment;
    m_numberOfAllocations++;

    return (void*)alignedAddress;
}

void LinearAllocator::deallocate(void* p)
{

}

void LinearAllocator::clear()
{
    m_numberOfAllocations = 0;
    m_memoryUsed = 0;
    m_currentPosition = m_start;
}
