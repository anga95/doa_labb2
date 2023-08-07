import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import os
import datetime


def load_and_prepare_data(filepath):
    data = pd.read_csv(filepath)
    data['Data size'] = data['Data size'].astype(int)
    return data


def plot_all_combined_graphs(data, save_dir):
    plt.figure(figsize=(15, 10))

    # Creating a line plot with seaborn
    sns.lineplot(x='Data size', y='Time taken(ms)', hue='Algorithm', style='datapattern', data=data)

    # Adding title and labels
    plt.title('Time taken by Sorting Algorithms for different Data sizes and patterns')
    plt.xlabel('Data Size')
    plt.ylabel('Time taken (ms)')

    # Displaying the plot
    plt.savefig(f'{save_dir}/all.png')
    plt.show()


def plot_heatmap(heatmap_data, save_dir):
    # Group the data by Algorithm, Data size, and datapattern, then calculate the mean of Time taken
    heatmap_data = heatmap_data.groupby(['Algorithm', 'Data size', 'datapattern'])['Time taken(ms)'].mean().reset_index()

    # Pivot the data to create a matrix where rows represent algorithms, columns represent data sizes, and cells are colored by average time
    heatmap_data_pivot = heatmap_data.pivot_table(index=['Algorithm', 'datapattern'], columns='Data size',
                                                  values='Time taken(ms)')

    plt.figure(figsize=(15, 10))

    # Create a heatmap with seaborn
    sns.heatmap(heatmap_data_pivot, cmap="YlGnBu", linewidths=.5)

    # Add a title
    plt.title('Heatmap of Average Time taken by Sorting Algorithms for Different Data Sizes and Patterns')

    plt.savefig(f'{save_dir}/heatmap.png')
    plt.show()


def plot_sorted_heatmap(heatmap_data, save_dir):
    mean_times = heatmap_data.groupby(['Algorithm', 'datapattern'])['Time taken(ms)'].mean()

    # Sort the index of the pivoted data according to the mean times
    sorted_index = mean_times.sort_values(ascending=False).index
    heatmap_data_pivot = heatmap_data.pivot_table(index=['Algorithm', 'datapattern'], columns='Data size',
                                                  values='Time taken(ms)')

    heatmap_data_pivot_sorted = heatmap_data_pivot.reindex(sorted_index)

    plt.figure(figsize=(15, 10))

    # Create a sorted heatmap with seaborn
    sns.heatmap(heatmap_data_pivot_sorted, cmap="YlGnBu", linewidths=.5)

    # Add a title
    plt.title('Sorted Heatmap of Average Time taken by Sorting Algorithms for Different Data Sizes and Patterns')

    plt.savefig(f'{save_dir}/sorted_heatmap.png')
    plt.show()


def plot_facetgrid(data, save_dir):
    g = sns.FacetGrid(data, col="Algorithm", col_wrap=2, height=4, aspect=1.5)
    g = g.map(sns.lineplot, "Data size", "Time taken(ms)", "datapattern", palette="tab10", linewidth=2.5)
    g.add_legend(title="Data Pattern", bbox_to_anchor=(1.1, 1), loc='upper left')
    g.set_titles("{col_name}")
    g.set_axis_labels("Data Size", "Time taken (ms)")
    plt.savefig(f'{save_dir}/facetgrid.png', bbox_inches='tight')
    plt.show()


def plot_std_sort(data, save_dir):
    std_sort_data = data[data['Algorithm'] == 'std::sort']
    sns.lineplot(x='Data size', y='Time taken(ms)', hue='datapattern', data=std_sort_data, palette="tab10",
                 linewidth=2.5)
    plt.title('Performance of std::sort for Different Data Sizes and Patterns')
    plt.xlabel('Data Size')
    plt.ylabel('Time taken (ms)')
    plt.legend(title='Data Pattern')
    plt.savefig(f'{save_dir}/std_sort.png')
    plt.show()


def main():
    # Get the current date and time
    now = datetime.datetime.now()
    now_str = now.strftime('%Y%m%d_%H%M%S')
    # Create a directory with the current date and time as its name
    os.makedirs(now_str, exist_ok=True)

    data = load_and_prepare_data('data.csv')
    plot_all_combined_graphs(data, now_str)
    plot_heatmap(data, now_str)
    plot_sorted_heatmap(data, now_str)
    plot_facetgrid(data, now_str)
    plot_std_sort(data, now_str)


if __name__ == "__main__":
    main()
