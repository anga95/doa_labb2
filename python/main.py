import pandas as pd
import matplotlib.pyplot as plt


def plot_all_combined_graphs(data):
    data_patterns = ['random', 'ascending', 'descending', 'constant']
    algorithms = data['Algorithm'].unique()
    nrows, ncols = 2, 2

    fig, axes = plt.subplots(nrows=nrows, ncols=ncols, figsize=(12, 8))
    plt.subplots_adjust(hspace=0.4, wspace=0.3)

    for i, data_pattern in enumerate(data_patterns):
        ax = axes[i // ncols, i % ncols]

        for algorithm in algorithms:
            algorithm_data = data[(data['Algorithm'] == algorithm) & (data['datapattern'] == data_pattern)]
            ax.plot(algorithm_data['Data size'], algorithm_data['Time taken(ms)'], marker='o', label=algorithm)

        ax.set_xlabel('Data size')
        ax.set_ylabel('Time taken (ms)')
        ax.set_title(f'{data_pattern.capitalize()} data')
        ax.legend()
        ax.grid()

    fig.suptitle('Comparison of Sorting Algorithms', fontsize=16)
    plt.savefig('All_Combined_data_graphs.png')
    plt.show()


def plot_combined_graph(data, data_pattern):
    algorithms = data['Algorithm'].unique()

    for algorithm in algorithms:
        algorithm_data = data[(data['Algorithm'] == algorithm) & (data['datapattern'] == data_pattern)]
        plt.plot(algorithm_data['Data size'], algorithm_data['Time taken(ms)'], marker='o', label=algorithm)

    plt.xlabel('Data size')
    plt.ylabel('Time taken (ms)')
    plt.title(f'Comparison of Sorting Algorithms ({data_pattern} data)')
    plt.legend()
    plt.grid()
    plt.savefig(f'Comparison_graph_{data_pattern}.png')
    plt.show()


def plot_individual_graphs(data, data_pattern):
    algorithms = data['Algorithm'].unique()

    for algorithm in algorithms:
        algorithm_data = data[(data['Algorithm'] == algorithm) & (data['datapattern'] == data_pattern)]
        plt.plot(algorithm_data['Data size'], algorithm_data['Time taken(ms)'], marker='o', label=algorithm)

        plt.xlabel('Data size')
        plt.ylabel('Time taken (ms)')
        plt.title(f'{algorithm} Algorithm ({data_pattern} data)')
        plt.legend()
        plt.grid()
        plt.savefig(f'{algorithm}_graph_{data_pattern}.png')
        plt.show()


data = pd.read_csv('combined_data.csv')
data_patterns = ['random', 'ascending', 'descending', 'constant']

# Plot combined graph for a specific data pattern

for data_pattern in data_patterns:
    plot_combined_graph(data, data_pattern)

plot_all_combined_graphs(data)

# Plot individual graphs for a specific data pattern
# for data_pattern in data_patterns:
#    plot_individual_graphs(data, data_pattern)
