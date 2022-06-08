#include "defines.h"
#include "asserts.h"

class Allocator
{
    public:
        Allocator(u64 size, void* start) 
            : m_start(start), m_totalSize(size), m_memoryUsed(0), m_numberOfAllocations(0) {}

        virtual ~Allocator()
        {
            OGLR_ASSERT(m_numberOfAllocations == 0 && m_memoryUsed == 0);
            m_start = nullptr;
            m_totalSize = 0;
        }

        virtual void* allocate(u64 size, u64 alignment = 4) = 0;
        virtual void deallocate(void* p) = 0;
        void* getStart() const { return m_start; }
        u64 getSize() const { return m_totalSize; }
        u64 getMemoryUsed() const { return m_memoryUsed; }
        u64 getNumberOfAllocations() const { return m_numberOfAllocations; }

    protected:
        u64 m_totalSize;
        u64 m_memoryUsed;
        u64 m_numberOfAllocations;
        void* m_start;
};

class LinearAllocator final : public Allocator  
{
    public:
        LinearAllocator(u64 size, void* start);
        ~LinearAllocator();

        void* allocate(u64 size, u64 alignment) override;
        void deallocate(void* p) override;
        void clear();
    
    private:
        void* m_currentPosition;
};