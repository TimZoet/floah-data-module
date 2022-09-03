#pragma once

namespace floah
{
    class DataSource;

    class DataListener
    {
    public:
        ////////////////////////////////////////////////////////////////
        // Constructors.
        ////////////////////////////////////////////////////////////////

        DataListener() = default;

        DataListener(const DataListener&) = default;

        DataListener(DataListener&&) noexcept = default;

        virtual ~DataListener() noexcept = default;

        DataListener& operator=(const DataListener&) = delete;

        DataListener& operator=(DataListener&&) noexcept = delete;

        ////////////////////////////////////////////////////////////////
        // Events.
        ////////////////////////////////////////////////////////////////

        virtual void onDataSourceUpdate(DataSource& source) = 0;
    };
}  // namespace floah
