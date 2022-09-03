#pragma once

////////////////////////////////////////////////////////////////
// Standard includes.
////////////////////////////////////////////////////////////////

#include <concepts>
#include <cstdint>

////////////////////////////////////////////////////////////////
// Current target includes.
////////////////////////////////////////////////////////////////

#include "floah-data/i_value_data_source.h"

namespace floah
{
    class IIntegralValueDataSource : public IValueDataSource
    {
    public:
        ////////////////////////////////////////////////////////////////
        // Constructors.
        ////////////////////////////////////////////////////////////////

        IIntegralValueDataSource() = default;

        IIntegralValueDataSource(const IIntegralValueDataSource&) = delete;

        IIntegralValueDataSource(IIntegralValueDataSource&&) noexcept = delete;

        ~IIntegralValueDataSource() noexcept override = default;

        IIntegralValueDataSource& operator=(const IIntegralValueDataSource&) = delete;

        IIntegralValueDataSource& operator=(IIntegralValueDataSource&&) noexcept = delete;

        ////////////////////////////////////////////////////////////////
        // Getters.
        ////////////////////////////////////////////////////////////////

        template<std::integral T>
        [[nodiscard]] T get()
        {
            T val = 0;
            getIntegral(val);
            return val;
        }

    protected:
        virtual void getIntegral(int8_t&)   = 0;
        virtual void getIntegral(int16_t&)  = 0;
        virtual void getIntegral(int32_t&)  = 0;
        virtual void getIntegral(int64_t&)  = 0;
        virtual void getIntegral(uint8_t&)  = 0;
        virtual void getIntegral(uint16_t&) = 0;
        virtual void getIntegral(uint32_t&) = 0;
        virtual void getIntegral(uint64_t&) = 0;

        ////////////////////////////////////////////////////////////////
        // Setters.
        ////////////////////////////////////////////////////////////////

    public:
        template<std::integral T>
        void set(T val)
        {
            setIntegral(val);
            emitDataSourceUpdate();
        }

    protected:
        virtual void setIntegral(int8_t)   = 0;
        virtual void setIntegral(int16_t)  = 0;
        virtual void setIntegral(int32_t)  = 0;
        virtual void setIntegral(int64_t)  = 0;
        virtual void setIntegral(uint8_t)  = 0;
        virtual void setIntegral(uint16_t) = 0;
        virtual void setIntegral(uint32_t) = 0;
        virtual void setIntegral(uint64_t) = 0;
    };
}  // namespace floah
