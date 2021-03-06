#pragma once

////////////////////////////////////////////////////////////////
// Current target includes.
////////////////////////////////////////////////////////////////

#include "floah-data/data_source.h"

namespace floah
{
    class IBoolDataSource : public DataSource
    {
    public:
        ////////////////////////////////////////////////////////////////
        // Constructors.
        ////////////////////////////////////////////////////////////////

        IBoolDataSource() = default;

        IBoolDataSource(const IBoolDataSource&) = delete;

        IBoolDataSource(IBoolDataSource&&) noexcept = delete;

        ~IBoolDataSource() noexcept override = default;

        IBoolDataSource& operator=(const IBoolDataSource&) = delete;

        IBoolDataSource& operator=(IBoolDataSource&&) noexcept = delete;

        ////////////////////////////////////////////////////////////////
        // Getters.
        ////////////////////////////////////////////////////////////////

        [[nodiscard]] virtual bool get() = 0;

        ////////////////////////////////////////////////////////////////
        // Setters.
        ////////////////////////////////////////////////////////////////

        virtual void set(bool v) = 0;

        virtual void toggle() = 0;
    };
}  // namespace floah
