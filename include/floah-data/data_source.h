#pragma once

namespace floah
{
    class DataSource
    {
    public:
        ////////////////////////////////////////////////////////////////
        // Constructors.
        ////////////////////////////////////////////////////////////////

        DataSource();

        DataSource(const DataSource&) = delete;

        DataSource(DataSource&&) noexcept = delete;

        virtual ~DataSource() noexcept;

        DataSource& operator=(const DataSource&) = delete;

        DataSource& operator=(DataSource&&) noexcept = delete;
    };
}  // namespace floah
